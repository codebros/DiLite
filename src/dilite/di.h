#ifndef BASEIOC_H
#define BASEIOC_H

#include <stdlib.h>
#include <sstream>
#include <map>
#include <typeinfo>
#include <iostream>
#include <stdexcept>
#include <string>
#include <stdarg.h>

#include "singleton.h"

namespace DiLite
{
	/**
	Template used to create instance of specific type T.

	@return Void pointer to object instance.
	*/
	template<typename T> void* CreateInstance() { return new T; }

	/**
	The Dependency Injection (DI) container class.

	@author SW801
	*/
	class BaseDI
	{
		private:
			/** A map of <TypeId, function pointer> to create object instances */
			std::map<std::string, void*(*)()> _objectConstructors;

			/** A map of <TypeId, void pointer> to refer to singleton instances */
			std::map<std::string, void*> _singletons;

			/**
			Checks if an object constructor or singleton of type I has been registered.
			*/
			template<typename I> void CheckExistence()
			{
				if(_singletons.find(typeid(I).name()) != _singletons.end() || _objectConstructors.find(typeid(I).name()) != _objectConstructors.end())
					throw std::runtime_error(((std::string) typeid(I).name()) + " is already bound.");
			}
			
			/**
				Type parameter constraint: checks that T is derived from B
				Courtesy of: Bjarne Stroustrup,
				http://www2.research.att.com/~bs/bs_faq2.html#constraints
			*/
			template<class T, class B> struct Derived_from
			{
				static void constraints(T* p)
				{
					B* pb = p;
				}
				Derived_from()
				{
					void(*p)(T*) = constraints;
				}
			};

		public:
			/**
			Bind type I in transient scope using construction function.
			Each time resolved, a new instance is created and returned.

			@param pt2func Function pointer to construction function.
			*/
			template<typename I> void Bind(I*(*pt2func)())
			{
				CheckExistence<I>();
				_objectConstructors[typeid(I).name()] = (void*(*)())pt2func;
			}

			/**
			Bind type I to type T in transient scope using default constructor of T.
			Each time resolved, a new instance is created and returned.
			*/
			template<typename I, typename T> void Bind()
			{
				Derived_from<T,I>();
				CheckExistence<I>();
				_objectConstructors[typeid(I).name()] = &CreateInstance<T>;
			}

			/**
			Bind type I to type T in singleton scope using default constructor of T.
			Each time resolved, the same instance is returned.
			*/
			template<typename I, typename T> void BindSingle()
			{
				Derived_from<T,I>();
				CheckExistence<I>();
				_singletons[typeid(I).name()] = &Singleton<T>::GetInstance();
			}

			/**
			Bind type I to type T in singleton scope using construction function.
			Each time resolved, the same instance is returned.

			@param pt2func Function pointer to construction function.
			*/
			template<typename I, typename T> void BindSingle(I*(*pt2func)())
			{
				Derived_from<T,I>();
				CheckExistence<I>();
				_singletons[typeid(I).name()] = &Singleton<T>::CreateInstance((void*(*)())pt2func);
			}

			/**
			Resolve an instance of the desired type/interface.

			Object may be pre-existing if registered as singleton.
			Otherwise lazily constructed using an object constructor.
			*/
			template<typename I> I* Resolve()
			{
				// Check if "resolvable" from singleton scope
				if(_singletons.find(typeid(I).name()) != _singletons.end())
					return ((I*)_singletons[typeid(I).name()]);

				// Check if "resolvable" from transient scope
				if(_objectConstructors.find(typeid(I).name()) != _objectConstructors.end())
					return ((I*)_objectConstructors[typeid(I).name()]());

				// Binding not found
				throw std::runtime_error(((std::string) typeid(I).name()) + " is not bound.");
			}

			/**
			Unbinds every registered object constructor and singleton instance.
			*/
			template<typename I> void Unbind()
			{
				// Unbind all objects in transient scope
				std::map<std::string, void*(*)()>::iterator it_transients = _objectConstructors.find(typeid(I).name());

				if (it_transients != _objectConstructors.end())
				{
					_objectConstructors.erase(it_transients);
				}

				// Unbind all objects in singleton scope
				std::map<std::string, void*>::iterator it_singletons = _singletons.find(typeid(I).name());

				if (it_singletons != _singletons.end())
				{
					_singletons.erase(it_singletons);
				}
			}
	};

	/**
	Typedefinition of the Singleton DI container.
	*/
	typedef Singleton<BaseDI> DI;
}

#endif

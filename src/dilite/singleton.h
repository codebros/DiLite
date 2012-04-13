#ifndef SINGLETON_H_SW8
#define SINGLETON_H_SW8

#include <cassert>
#include <boost/thread/mutex.hpp>

namespace DiLite 
{
	/**
	Template for any class that should be in
	singleton scope.
	*/
	template<typename T> class Singleton
	{
		private:
			/** Indicates if the singleton has been destructed */
			static bool _isDestructed;

			/** The mutex used by the singleton to enable thread-safety */
			static boost::mutex& GetMutex()
			{
				static boost::mutex mutex;
				return mutex;
			}

			/** Prevent construction of Singleton class */
			Singleton() {}

			/** Prevent destruction of Singleton class */
			~Singleton() { _isDestructed = true; }

			/** Prevent copy of Singleton */
			Singleton(Singleton const&);

			/** Prevent assignment to Singleton */
			void operator=(Singleton const&);

		public:
			/**
			Gets the instance wrapped by the Singleton.

			@return A singleton object of type T.
			*/
			static T& GetInstance()
			{
				assert(!_isDestructed);
				boost::mutex::scoped_lock lock(GetMutex());
				static T instance;
				return instance;
			}

			/**
			Creates and gets an instance of type T in singleton scope.

			@param ctor A function pointer to a construction function returning T.
			@return A singleton object of type T.
			*/
			static T& CreateInstance(void*(*ctor)())
			{
				assert(!_isDestructed);
				boost::mutex::scoped_lock lock(GetMutex());
				static T instance = *((T*)ctor());
				return instance;
			}
	};

	/**
	Force creation of the mutex before main() is called.
	This happens as a consequence of the comma-operator and semantics of sequence points.
	*/
	template<typename T> bool Singleton<T>::_isDestructed = (Singleton<T>::GetMutex(), false);
}
#endif

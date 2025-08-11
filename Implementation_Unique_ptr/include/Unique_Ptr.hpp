#pragma once

namespace Implementation_Unique_ptr
{
	template<typename  T>
	class unique_ptr
	{
	private:
		T* ptr;
		//delete copy constructor 
		unique_ptr(const unique_ptr&) = delete;
        // delete copy assignment operator
		unique_ptr& operator=(const unique_ptr&) = delete;

	public:

		//constructors and destructors
		unique_ptr() noexcept
			:ptr(nullptr) {}

		//nullptr ctor and assignment to bind to nulltptrs
		unique_ptr(std::nullptr_t) noexcept                                 //to bind to nullptr and allow unique_ptr up = nullptr conversions   
			:unique_ptr() {
			std::cout << "nullptr constructor"<< std::endl;
		}


		unique_ptr& operator=(std::nullptr_t) noexcept
		{
			std::cout << "nullptr asignment" << std::endl;
			this->reset();
			return *this;
		}

		explicit unique_ptr(T* newptr) noexcept                             //explicit to disallow implicit conversions from T* ex int *p ; unique_ptr up = p; 
		{
			this->ptr = newptr;
		}

		~unique_ptr() noexcept
		{
			delete ptr;
		}

		//move semantics 
		unique_ptr(unique_ptr &&rhs) noexcept
			:ptr{rhs.ptr}
		{
			std::cout << "move ctor";
			rhs.ptr = nullptr;
		}
        //move assignment operator
		unique_ptr& operator = (unique_ptr&& rhs) noexcept              // unique_ptr<int> *const this
		{
			delete ptr;
			ptr = nullptr;
			this->swap(rhs);
			/*ptr = rhs.ptr;
			rhs.ptr = nullptr;*/
            delete rhs.ptr; // delete the current pointer to avoid memory leak
            rhs.ptr = nullptr; //set rhs to nullptr to avoid double deletion
			return *this;
		}

		//move semantics from derived types    when a <U> is derived from <T> and upcasting is required
		template<typename U>
		unique_ptr(unique_ptr<U>&& rhs) noexcept
		{
			std::cout << "derived move ctor"<< std::endl;
			unique_ptr<T> newptr(rhs.release());             //will convert derived typer to base
			this->swap(newptr);
		}

		template<typename U>
		unique_ptr& operator =(unique_ptr<U>&& rhs) noexcept
		{
        std::cout << "derived move assignment" << std::endl;
			unique_ptr<T> newptr(rhs.release());             //will convert derived typer to base
			this->swap(newptr);
			return *this;
		}

		//derefrencing and member access
		T& operator *() const noexcept
		{
			return *ptr;
		}

		T* operator ->() const noexcept
		{
			return ptr;
		}

		T* get() const noexcept
		{
			return ptr;
		}

		//operators

		explicit operator bool() const  noexcept                        //convertion operator //explicit to avoid implicit conversion of type if( up1<T1>..bool == up2<T2>...bool)
		{
			return ptr;
		}

		friend bool operator ==(const unique_ptr<T>& lhs, const unique_ptr<T>& rhs) 
		{
        //    return *(lhs.ptr) == *(rhs.ptr); //compare the raw pointers
			return lhs.get() == rhs.get();
		}

		friend bool operator !=(const unique_ptr<T>& lhs, const unique_ptr<T>& rhs) 
		{
			return !(lhs == rhs);	
		}

		//utility
		T* release() noexcept
		{
			T* old_ptr = this->ptr;
			ptr = nullptr;
			return old_ptr;
		}

		void reset(T *newptr=nullptr)
		{
			delete ptr;
			ptr = newptr;
		}
			
		void swap(unique_ptr<T> &rhs) noexcept 
		{
			std::swap(ptr, rhs.ptr);
		}
	};
}

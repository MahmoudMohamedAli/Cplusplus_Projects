#include<iostream>

using namespace std;

template <typename T>
class shard_ptr_class {
private:
	T* ptr;
	int *count;	//shared. shallow copied

	inline void dec_count() {
		(*count)--;
	}

	inline void inc_count() {
		(*count)++;
	}

public:
	shard_ptr_class(T* _ptr) {
		ptr = _ptr;
		count = new int(1);
	}

	~shard_ptr_class() {
		//cout << "In ~CuShPtr" << endl;
		if(count != nullptr) {
			dec_count();
			if(*count == 0) {
				delete ptr;
				delete count;
			}
            ptr = nullptr;
            count = nullptr;
		}
	}

	shard_ptr_class(const shard_ptr_class<T>& other) {
		ptr = other.ptr;
		count = other.count;
		inc_count();
	}
	shard_ptr_class<T>& operator=(const shard_ptr_class<T>& other) {
		//TODO: only if count != nullptr?
		ptr = other.ptr;
		count = other.count;
		inc_count();
		return *this;
	}

	int use_count() const {
		if(count != nullptr)
			return *count;
		else
			return 0;
	}

	void reset() {
		if(count != nullptr) {
			dec_count();
			if(*count == 0) {
                if(ptr != nullptr)
                {
                    //cout << "Deleting ptr in reset" << endl;
                    delete ptr;
                }
				delete count;
			}
			count = nullptr;
			ptr = nullptr;
		}
	}

	T* operator*() 
    {
        if (ptr == nullptr) {
            throw std::runtime_error("Dereferencing a null pointer");
        }

		return ptr;
	}

	T* operator ->() 
    {
    if (ptr == nullptr) {
        throw std::runtime_error("Accessing a member of a null pointer");
       
    }
		return ptr;
	}
};
#pragma once

#include <array>
#include <cstring>

# define barrier() __asm__ __volatile__("": : :"memory")

constexpr bool IsPowOfTwo(size_t size) {
	return ((size < 2) || (size & (size - 1))) ? false : true;
}

// SIZE: the number of elements in the fifo, this must be a power of 2
template<typename T, size_t SIZE>
class Kfifo {
 public:
  Kfifo() {	
	static_assert(SIZE >= 2, "SIZE must large and equal 2");
	static_assert(IsPowOfTwo(SIZE), "SIZE must is pow of two");
  }
  size_t In(const T* buf, size_t len) {
	  size_t l = Unused();
	  if (len > l) {
		  len = l;
	  }

	  CopyIn(buf, len, in_);
	  in_ += len;
	  return len;
  }
  
  size_t Peek(T* buf, size_t len) {
	size_t l = in_ - out_;
	if (len > l) {
	  len = l;
	}
	CopyOut(buf, len, out_);
	return len;
  }

  size_t Out(T* dst, size_t len) {
	  len = Peek(dst, len);
	  out_ += len;
	  return len;
  }

  size_t Unused() {
	return (mask_ + 1) - (in_ - out_);
  }

 private:
  void CopyIn(const T* src, size_t len, size_t off) {
	size_t size = mask_ + 1;
	// 取余
	off &= mask_;
	if (esize_ != 1) {
	  len *= esize_;
	  size *= esize_;
	  off *= esize_;
	}
	size_t l = std::min(len, size - off);
	memcpy(reinterpret_cast<char*>(data_.data()) + off, src, l);
	memcpy(data_.data(), src + l, len - l);
	// 内存写屏障，不能让in_的写入在之前发生
	barrier();
  }

  void CopyOut(T* dst, size_t len, size_t off) {
	size_t size = mask_ + 1;
	// 取余
	off &= mask_;
	if (esize_ != 1) {
	  len *= esize_;
	  size *= esize_;
	  off *= esize_;
	}
	size_t l = std::min(len, size - off);
	memcpy(dst, (reinterpret_cast<char*>(data_.data())) + off, l);
	memcpy(reinterpret_cast<char*>(dst) + l, data_.data(), len - l);
	// 写屏障，不能让out_的写入在之前发生
	barrier();
  }
  size_t	in_{0};
  size_t	out_{0};
  size_t	mask_{SIZE - 1};
  size_t 	esize_{sizeof(T)};
  std::array<T, SIZE>	data_;
};


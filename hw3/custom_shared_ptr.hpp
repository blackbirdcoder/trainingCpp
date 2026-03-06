#pragma once
#include <cstddef>

namespace Homework {
template <typename T> class custom_shared_ptr {
public:
  custom_shared_ptr();
  custom_shared_ptr(T *val);
  custom_shared_ptr(const custom_shared_ptr &obj);
  custom_shared_ptr &operator=(const custom_shared_ptr &obj);
  ~custom_shared_ptr();
  T &operator*() const;
  T *operator->() const;
  T *get() const;
  explicit operator bool() const;

private:
  T *ptr;
  std::size_t *count;
};
} // namespace Homework

template <typename T> Homework::custom_shared_ptr<T>::custom_shared_ptr() {
  this->ptr = nullptr;
  this->count = nullptr;
}

template <typename T>
Homework::custom_shared_ptr<T>::custom_shared_ptr(T *val) {
  this->ptr = val;
  this->count = new std::size_t(1);
}

template <typename T>
Homework::custom_shared_ptr<T>::custom_shared_ptr(
    const custom_shared_ptr &obj) {
  this->ptr = obj.ptr;
  this->count = obj.count;

  if (this->count != nullptr) {
    (*this->count)++;
  }
}

template <typename T>
Homework::custom_shared_ptr<T> &
Homework::custom_shared_ptr<T>::operator=(const custom_shared_ptr &obj) {
  if (this == &obj) {
    return *this;
  }

  if (this->count != nullptr) {
    (*this->count)--;

    if ((*this->count) == 0) {
      delete this->ptr;
      delete this->count;
    }
  }

  this->ptr = obj.ptr;
  this->count = obj.count;

  if (this->count != nullptr) {
    (*this->count)++;
  }

  return *this;
}

template <typename T> Homework::custom_shared_ptr<T>::~custom_shared_ptr() {
  if (this->count == nullptr) {
    return;
  } else {
    (*this->count)--;
    if (*count == 0) {
      delete this->ptr;
      delete this->count;
    }
  }
}

template <typename T> T &Homework::custom_shared_ptr<T>::operator*() const {
  return (*this->ptr);
}

template <typename T> T *Homework::custom_shared_ptr<T>::operator->() const {
  return this->ptr;
}

template <typename T> T *Homework::custom_shared_ptr<T>::get() const {
  return this->ptr;
}

template <typename T> Homework::custom_shared_ptr<T>::operator bool() const {
  return (this->ptr != nullptr);
}
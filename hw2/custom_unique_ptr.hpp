#pragma once

namespace Homework {
template <typename T> class custom_unique_ptr {
public:
  custom_unique_ptr(const custom_unique_ptr &obj) = delete;
  custom_unique_ptr &operator=(const custom_unique_ptr &obj) = delete;
  custom_unique_ptr();
  custom_unique_ptr(T *val);
  ~custom_unique_ptr();
  T &operator*() const;
  T *operator->() const;
  T *get() const;
  explicit operator bool() const;

private:
  T *ptr;
};
} // namespace Homework

template <typename T> Homework::custom_unique_ptr<T>::custom_unique_ptr() {
  this->ptr = nullptr;
}

template <typename T> Homework::custom_unique_ptr<T>::~custom_unique_ptr() {
  delete this->ptr;
}

template <typename T>
Homework::custom_unique_ptr<T>::custom_unique_ptr(T *val) {
  this->ptr = val;
}

template <typename T> T &Homework::custom_unique_ptr<T>::operator*() const {
  return (*this->ptr);
}

template <typename T> T *Homework::custom_unique_ptr<T>::operator->() const {
  return this->ptr;
}

template <typename T> Homework::custom_unique_ptr<T>::operator bool() const {
  return (this->ptr != nullptr);
}

template <typename T> T *Homework::custom_unique_ptr<T>::get() const {
  return this->ptr;
}
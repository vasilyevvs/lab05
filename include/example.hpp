// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_
#include "iostream"
auto example() -> void;
template <typename T>
class Stack{
    private:
    struct Node
    {
      T field;
      struct Node *next;
    };
    Node * node;
    T * mass;

 public:
  Stack(){
    node = new Node;
    mass = new T[10];
  }
  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;
  template <typename ... Args>
  void push_emplace(Args&&... value);
  Stack(const Stack & st) = delete;
  Stack& operator=(const Stack & st) = delete;

  Stack(Stack && st) = delete;
  Stack& operator=(Stack && st)  noexcept;
};
template <typename T>
void Stack<T>::push(T&& value)
{
  Node *c = new Node();
  c->value=std::move(value);
  c->next=std::move(node);
  node=c;
}
template <typename T>
void Stack<T>::push(const T& value)
{
  Node *c = new Node();
  c->value=value;
  c->next=node;
  node=c;
}
template <typename T>
void Stack<T>::pop() {
  Node* a;
  if (node != NULL) {
    a = node;
    node = a->next;
    return a->value;
  } else {
    throw "Stack is empty!";
  }
}
template <typename T>
const T& Stack<T>::head() const {
  return node->value;
}
template <typename T>
template <typename ... Args>
void Stack<T>::push_emplace(Args&&... value)
{
  Node *c = new Node();
  c->value= T(std::forward<Args>(value)...);
  c->next=node;
  node=c;
}
#endif // INCLUDE_EXAMPLE_HPP_

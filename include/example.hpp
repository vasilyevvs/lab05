// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

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

  void push(T&& value)
  {
      Node *c = new Node();
      c->value=value;
      c->next=node;
      node=c;

  }
  void push(const T& value)
  {
    Node *c = new Node();
    c->value=value;
    c->next=node;
    node=c;
  }
  void pop() {
    Node* a;
    if (node != NULL) {
      a = node;
      node = a->next;
      return a->value;
    } else {
      throw "Stack is empty!";
    }
  }
      Stack(const Stack & st) = delete;
      Stack& operator=(const Stack & st) = delete;

      Stack(Stack && st) = delete;
      Stack& operator=(Stack && st)  noexcept;

  const T& head() const;
};

#endif // INCLUDE_EXAMPLE_HPP_

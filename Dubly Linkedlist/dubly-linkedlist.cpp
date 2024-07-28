#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *prev;
  Node *next;
  Node(int val)
  {
    this->val = val;
    this->prev = NULL;
    this->next = NULL;
  }
};

void insert_at_tail(Node *&head, int value)
{
  Node *newNode = new Node(value);
  if (head == NULL)
  {
    head = newNode;
    cout << endl
         << "Inserted at head" << endl
         << endl;
    return;
  }
  Node *tmp = head;
  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }

  tmp->next = newNode;
  newNode->prev = tmp;
  cout << endl
       << "Inserted at tail" << endl
       << endl;
}

void print_linked_list(Node *head, string type = "forward")
{
  cout << endl;
  cout << "Your Linked List: ";
  if (type == "reverse")
  {
    Node *tmp = head;
    while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
    while (tmp != NULL)
    {
      cout << tmp->val << " ";
      tmp = tmp->prev;
    }
  }
  else
  {
    Node *tmp = head;
    while (tmp != NULL)
    {
      cout << tmp->val << " ";
      tmp = tmp->next;
    }
  }

  cout << endl
       << endl;
}

void insert_at_position(Node *head, int pos, int v)
{
  Node *newNode = new Node(v);
  Node *tmp = head;
  for (int i = 1; i <= pos - 1; i++)
  {
    tmp = tmp->next;
    if (tmp == NULL)
    {
      cout << endl
           << "Invalid Index" << endl
           << endl;
      return;
    }
  }
  newNode->next = tmp->next;
  newNode->prev = tmp;
  tmp->next = newNode;
  cout << endl
       << endl
       << "Inserted at position " << pos << endl
       << endl;
}
void insert_at_head(Node *&head, int v)
{
  Node *newNode = new Node(v);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  cout << endl
       << "Inserted at head" << endl
       << endl;
}

void delete_from_position(Node *head, int pos)
{
  Node *tmp = head;
  for (int i = 1; i <= pos - 1; i++)
  {
    tmp = tmp->next;
    if (tmp == NULL)
    {
      cout << endl
           << "Invalid Index" << endl
           << endl;
      return;
    }
  }
  if (tmp->next == NULL)
  {
    cout << endl
         << "Invalid Index" << endl
         << endl;
    return;
  }
  Node *deleteNode = tmp->next;
  tmp->next = tmp->next->next;
  tmp->next->prev = tmp;
  delete deleteNode;
  cout << endl
       << "Deleted position " << pos << endl
       << endl;
}

void delete_head(Node *&head)
{
  if (head == NULL)
  {
    cout << endl
         << "Head is not available" << endl
         << endl;
    return;
  }
  Node *deleteNode = head;
  head = head->next;
  head->next->prev = NULL;
  delete deleteNode;
  cout << endl
       << "Deleted head" << endl
       << endl;
}
void delete_tail(Node *&head)
{
  if (head == NULL)
  {
    cout << endl
         << "Linked List is Already Empty" << endl
         << endl;
    return;
  }

  Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  if (tail->next != NULL)
  {
    tail->prev->next = NULL;
  }
  else
  {
    head = NULL;
  }
  delete tail;
  cout << endl
       << "Deleted tail" << endl
       << endl;
}
main()
{
  Node *head = NULL;
  while (true)
  {
    cout << "Option 1: Insert at Tail" << endl;
    cout << "Option 2: Print Linked List Forward" << endl;
    cout << "Option 3: Print Linked List Reverse" << endl;
    cout << "Option 4: Insert at any Position" << endl;
    cout << "Option 5: Insert at Head" << endl;
    cout << "Option 6: Delete from Position" << endl;
    cout << "Option 7: Delete from Head" << endl;
    cout << "Option 8: Delete from Tail" << endl;
    cout << "Option 9: Terminate" << endl;
    int op;
    cin >> op;
    if (op == 1)
    {
      cout << "Please enter value: ";
      int v;
      cin >> v;
      insert_at_tail(head, v);
    }
    else if (op == 2)
    {
      print_linked_list(head);
    }
    else if (op == 3)
    {
      print_linked_list(head, "reverse");
    }
    else if (op == 4)
    {
      int pos, v;
      cout << "Enter position: ";
      cin >> pos;
      cout << "Enter value: ";
      cin >> v;
      if (pos == 0)
      {
        insert_at_head(head, v);
      }
      else
      {
        insert_at_position(head, pos, v);
      }
    }
    else if (op == 5)
    {
      int v;
      cout << "Enter value: ";
      cin >> v;
      insert_at_head(head, v);
    }
    else if (op == 6)
    {
      int pos;
      cout << "Enter position: ";
      cin >> pos;
      if (pos == 0)
      {
        delete_head(head);
      }
      else
      {
        delete_from_position(head, pos);
      }
    }
    else if (op == 7)
    {
      delete_head(head);
    }
    else if (op == 8)
    {
      delete_tail(head);
    }
    else if (op == 9)
    {
      break;
    }
  }
  return 0;
}
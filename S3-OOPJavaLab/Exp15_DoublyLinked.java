import java.util.Scanner;

class DoublyLinkedList
{
 private Node head;

 class Node
{
private int data;
Node prev;
Node next;

Node(int data)
{
this.data = data;
this.prev = null;
this.next = null;
}
}

public void insertAtEnd(int data)
{
 Node temp = new Node(data);
if (head == null)
{
head = temp;
}
else
{
Node ptr = head;
while (ptr.next != null)
ptr = ptr.next;
ptr.next = temp;
temp.prev = ptr;
}
Display();
}

public void deleteFromFront()
{
if (head == null)
{
System.out.println("List Empty");
}
else
{
System.out.println("Deleted " + head.data);
head = head.next;
if (head != null)
head.prev = null;
}
Display();
}

public void deleteElement(int data)
{
    Node temp = head;
    if (head == null)
    {
        System.out.println("List Empty");
    }
    else
    {
        while (temp != null && temp.data != data)
            temp = temp.next;
        if (temp == null)
        {
            System.out.println("Element " + data + " not found");
            return;
        }
        /* Delete the node */
        if (temp.prev != null)
            temp.prev.next = temp.next;
        if (temp.next != null) // Add this check to avoid NullPointerException
            temp.next.prev = temp.prev;
        System.out.println("Deleted " + data);
    }
    Display();
}

public void Display()
{
Node temp = head;
if (head == null)
{
System.out.println("List Empty");
}
else
{
while (temp != null)
{
System.out.print(temp.data + " ");
temp = temp.next;
}
System.out.println();
}
}
}

public class DLL
{
public static void main(String args[])
{
DoublyLinkedList list = new DoublyLinkedList();
Scanner stdin = new Scanner(System.in);
int choice, element;
while (true)
{
System.out.println("1. Insert at end\n" +
"2. Delete from front\n" +
"3. Delete element\n" +
"4. Display list\n" +
"5. Exit\n");
System.out.print("Enter choice: ");
choice = stdin.nextInt();
stdin.nextLine();

switch (choice)
{

case 1:
System.out.print("Enter the element: ");
element = stdin.nextInt();
stdin.nextLine();
list.insertAtEnd(element);
break;

case 2:
list.deleteFromFront();
break;

case 3:
System.out.print("Enter the element: ");
element = stdin.nextInt();
stdin.nextLine();
list.deleteElement(element);
break;

case 4:
list.Display();
break;

case 5:
return;
default:
System.out.println("Invalid choice");
}
}
}
}
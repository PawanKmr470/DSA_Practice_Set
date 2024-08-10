int main() {
    singlyLL l;
    l.insertAtBegin(1);
    l.insertAtBegin(2);
    l.insertAtBegin(3);
    l.insertAtBegin(4);
    l.printSLL();
    l.reverse();
    l.printSLL();
    l.reverseRec();
    l.printSLL();
}
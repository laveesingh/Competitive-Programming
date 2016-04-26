Node* Insert(Node *head,int data)
{
    struct Node *temp, *node;
    node = (Node*) malloc(sizeof(Node));
    
    node -> data = data;
    node -> next = NULL;
    if (head == NULL){
        return node;
    }else{
        temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = node;
        return head;
    }
}
Node* RemoveDuplicates(Node *A){
	if (A == NULL || A -> next == NULL) return A;
	Node *cur;
	cur = A;
	while (cur -> next != NULL){
		if (cur -> data == cur -> next -> data){
			cur -> next = cur -> next -> next;
		}
		else{
			cur = cur -> next;
		}
	}
	return A;
}
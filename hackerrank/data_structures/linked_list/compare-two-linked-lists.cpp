
int CompareLists(Node *A, Node *B){
	while (A != NULL || B != NULL){
		if (A == NULL && B != NULL) return 0;
		if (B == NULL && A != NULL) return 0;
		if (A -> data != B -> data){
			return 0;
		}
		A = A -> next;
		B = B -> next;
	}
	return 1;
}
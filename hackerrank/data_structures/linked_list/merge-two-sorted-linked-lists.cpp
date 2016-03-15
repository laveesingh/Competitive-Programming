Node* MergeLists(Node *A, Node *B){
	Node *t, *ta, *tb,  *head;
	if (B == NULL) return A;
	if (A == NULL) return B;
	ta = A;
	tb = B;
	if (ta -> data < tb -> data){
		t = ta;
		ta = ta -> next;
	}else{
		t = tb;
		tb = tb -> next;
	}
	head = t;
	while (true){
		if (ta == NULL){
			t -> next = tb;
			break;
		}else if(tb == NULL){
			t -> next = ta;
			break;
		}
		if (ta -> data < tb -> data){
			t -> next = ta;
			ta = ta -> next;
			t = t-> next;
		}else{
			t -> next = tb;
			tb = tb -> next;
			t = t-> next;

		}
		
	}
	return head;
}
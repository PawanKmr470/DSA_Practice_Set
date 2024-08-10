#include <iostream>
using namespace std;

typedef struct NODE
{
	int data;
	struct NODE *next;
} NODE;

NODE * CreateList(NODE *);
void Display(NODE *);
void Search(NODE *, int);

NODE *InsertAtBeg(NODE *, int);
NODE *InsertAtEnd(NODE *, int);
NODE *InsertAfter(NODE *, int, int);
NODE *InsertBefore(NODE *,int, int);
NODE *InsertAtPos(NODE *, int, int);

NODE *Delete(NODE *, int);
NODE *DeleteBeg(NODE *);
NODE *DeleteEnd(NODE *);
NODE *DeleteAtPos(NODE *, int);
NODE *DeleteAfter(NODE *, int, int);
NODE *DeleteBefore(NODE *, int, int);

NODE *Reverse(NODE *);
NODE *RecRev(NODE *);

// AFTER EVERY MALLOC NULL CHECKING SHOULD BE PLACED !!!

int main()
{
	int choice, data, pos;
	NODE *Start = NULL;
	while(1)
	{
		printf("1.  Create List\n");
		printf("2.  Display\n");
		printf("3.  Search\n");

		printf("4.  Insert at beg\n");
		printf("5.  Insert at end\n");
		printf("6.  Insert after a node\n");
		printf("7.  Insert before a node\n");
		printf("8.  Insert at position\n");

		printf("9.  Delete the element\n");
		printf("10  Delete at beg\n");
		printf("11  Delete at End\n");
		printf("12  Delete at position\n");
		//printf("13. Delete after a node\n");
		//printf("14. Delete before a node\n");

		printf("15. Reverse linked list\n");
		printf("16. Reverse linked list recursively\n");
		printf("17  To Exit\n\n");
		printf("Enter the choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				Start = CreateList(Start);
				printf("\n");
				break;

			case 2:
				Display(Start);
				printf("\n");
				break;

			case 3:
				printf("Enter the element to be searched : ");
				scanf("%d",&data);
				Search(Start, data);
				printf("\n");
				break;

			case 4:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				Start = InsertAtBeg(Start, data);
				printf("\n");
				break;

			case 5:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				Start = InsertAtEnd(Start, data);
				printf("\n");
				break;

			case 6:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the position to insert     : ");
				scanf("%d",&pos);
				Start = InsertAfter(Start, data, pos);
				printf("\n");
				break;

			case 7:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the position to insert     : ");
				scanf("%d",&pos);
				Start = InsertBefore(Start, data, pos);
				printf("\n");
				break;

			case 8:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the position to insert     : ");
				scanf("%d",&pos);
				Start = InsertAtPos(Start, data, pos);
				printf("\n");
				break;

			case 9:
				printf("Enter the element to be deleted : ");
				scanf("%d",&data);
				Start = Delete(Start, data);
				printf("\n");
				break;

			case 10:
				Start = DeleteBeg(Start);
				printf("\n");
				break;

			case 11:
				Start = DeleteEnd(Start);
				printf("\n");
				break;

			case 12:
				printf("Enter the position to delete     : ");
				scanf("%d",&pos);
				Start = DeleteAtPos(Start, pos);
				printf("\n");
				break;

			case 15:
				Start = Reverse(Start);
				printf("\n");
				break;

			case 16:
				Start = RecRev(Start);
				printf("\n");
				break;

			case 17:
				return 0;

			default:
				printf("wrong choice selection\n");
				break;
		}

	}
	return 0;
}


NODE *CreateList(NODE *Start)
{
	int n,i,data;
	NODE *temp;
	printf("Enter the no of nodes : ");
	scanf("%d",&n);
	if (Start != NULL)
	{
		printf("Linked list already created\n");
		return Start;
	}
	if (n <= 0)
	{
		return Start;
	}
	for (i = 1; i <= n; i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		Start = InsertAtEnd(Start, data);
	}
	printf("\n");
	return Start;
}

void Display(NODE * Start)
{
	NODE *temp = Start;
	if (Start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("----------------------------------------------------------\n");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n----------------------------------------------------------\n");
	printf("\n");
}

void Search(NODE *Start, int val)
{
	NODE *pcur = Start;
	int pos = 1;
	if (Start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(pcur->data != val && pcur->next != NULL)
	{
		pos++;
		pcur = pcur->next;
	}
	if (pcur->next == NULL && pcur->data != val)
	{
		printf("Element not present in the list\n");
	}
	else
	{
		printf("position of the %d element is : %d\n", val, pos);
	}
	return;
}

NODE *Reverse(NODE *Start)
{
	NODE *pcur, *pnext, *prev;
	pcur = Start;
	prev = NULL;
	while(pcur != NULL)
	{
		pnext = pcur->next;		// taking backup of the next node
		pcur->next = prev;		// assign link of prev node to the current node
		prev = pcur;			// making current link as previous
		pcur = pnext;			// moving to the next node
	}
	Start = prev;
	return Start;
}

NODE *RecRev(NODE *pcur)
{
	NODE *Start;
	if (pcur == NULL || pcur->next == NULL)
	{
		Start = pcur;
		return Start;
	}
	Start = RecRev(pcur->next);
	pcur->next->next = pcur;
	pcur->next = NULL;
	return Start;
}

NODE *InsertAtEnd(NODE *Start, int val)
{
	NODE *pcur, *temp;
	if (Start == NULL)
	{
		temp = (NODE *)malloc(sizeof(NODE));
		temp->data = val;
		temp->next = NULL;
		Start = temp;
		return Start;
	}
	pcur = Start;
	while(pcur->next != NULL)
	{
		pcur = pcur->next;
	}
	temp = (NODE *)malloc(sizeof(NODE));
	temp->data = val;
	temp->next = NULL;
	pcur->next = temp;
	return Start;
}

NODE *InsertAtBeg(NODE *Start, int val)
{
	NODE *temp;
	temp = (NODE *)malloc(sizeof(NODE));
	temp->data = val;
	temp->next = Start;
	Start = temp;
	return Start;
}

NODE *InsertAtPos(NODE *Start, int val, int pos)
{
	int i;
	NODE *pcur, *pnext, *temp;
	pcur = Start;
	if (pos < 1)
	{
		printf("invalid position\n");
		return Start;
	}

	temp = (NODE *)malloc(sizeof(NODE));
	temp->data = val;
	if (pos == 1)
	{
		temp->next = Start;
		Start = temp;
		return Start;
	}
	for(i = 1; i < (pos - 1); i++)			// WHEN IT COMES TO POSITION REMEMBER THE HOPS IT REQUIRES TO BE AT THAT POSITION !
	{										// OR TO BE AT THE POSITION JUST BEFORE THE NODE !!!
		if (pcur != NULL)
		{
			pcur = pcur->next;
		}
		else
		{
			printf("invalid position\n");
			free(temp);
			return Start;
		}
	}
	pnext = pcur->next;
	temp->next = pnext;
	pcur->next = temp;
	return Start;
}

NODE *InsertAfter(NODE *Start, int val, int pos)
{
	int i;
	NODE *pcur, *pnext, *temp;
	pcur = Start;
	if (pos < 1)
	{
		printf("invalid position\n");
		return Start;
	}

	temp = (NODE *)malloc(sizeof(NODE));
	temp->data = val;
	if (pos == 1)
	{
		temp->next = Start->next;
		Start->next = temp;
		return Start;
	}
	for(i = 1; i < pos; i++)
	{
		if (pcur != NULL)
		{
			pcur = pcur->next;
		}
		else
		{
			printf("invalid position\n");
			free(temp);
			return Start;
		}
	}
	pnext = pcur->next;
	temp->next = pnext;
	pcur->next = temp;
	return Start;
}

NODE *InsertBefore(NODE *Start, int val, int pos)
{
	int i;
	NODE *pcur, *pnext, *temp;
	pcur = Start;
	if (pos < 1)
	{
		printf("invalid position\n");
		return Start;
	}

	temp = (NODE *)malloc(sizeof(NODE));
	temp->data = val;
	if (pos == 1)
	{
		temp->next = Start;
		Start = temp;
		return Start;
	}
	for(i = 1; i < (pos - 1); i++)
	{
		if (pcur != NULL)
		{
			pcur = pcur->next;
		}
		else
		{
			printf("invalid position\n");
			free(temp);
			return Start;
		}
	}
	pnext = pcur->next;
	temp->next = pnext;
	pcur->next = temp;
	return Start;
}

NODE *Delete(NODE *Start, int val)
{
	NODE *temp, *pcur;
	if (Start == NULL)
	{
		printf("List is empty\n");
		return Start;
	}
	pcur = Start;
	if (pcur->data == val)
	{
		pcur = Start->next;
		free(Start);
		Start = pcur;
		return Start;
	}
	while(pcur->next != NULL)
	{
		if (pcur->next->data != val)
		{
			pcur = pcur->next;
		}
		else
		{
			temp = pcur->next->next;
			free(pcur->next);
			pcur->next = temp;
			return Start;
		}
	}
	printf("Element not found\n");
	return Start;
}

NODE *DeleteBeg(NODE *Start)
{
	NODE *temp;
	if (Start == NULL)
	{
		printf("List is empty\n");
		return Start;
	}
	temp = Start->next;
	free(Start);
	Start = temp;
	return Start;
}

NODE *DeleteEnd(NODE *Start)
{
	NODE *temp, *prev;
	if (Start == NULL)
	{
		printf("List is empty\n");
		return Start;
	}
	if (Start->next == NULL)
	{
		free(Start);
		Start = NULL;
		return Start;
	}
	temp = Start;
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	free(temp);
	prev->next = NULL;
	return Start;
}

NODE *DeleteAtPos(NODE *Start, int pos)
{
	int i;
	NODE *pcur, *temp;
	pcur = Start;
	if (Start == NULL)
	{
		printf("List is empty\n");
		return Start;
	}
	if (pos == 1)
	{
		temp = Start->next;
		free(Start);
		Start = temp;
		return Start;
	}
	for (i = 1; i < (pos - 1); i++)
	{
		if (pcur != NULL)
		{
			pcur = pcur->next;
		}
		else
		{
			printf("invalid position\n");
			return Start;
		}
	}
	temp = pcur->next->next;
	free(pcur->next);
	pcur->next = temp;
	return Start;
}
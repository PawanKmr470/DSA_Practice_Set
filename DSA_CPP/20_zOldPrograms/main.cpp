#include<iostream>
using namespace std;

//// first name space
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}
//// second name space
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}
//using namespace first_space;
//using namespace second_space;
using first_space::func;
//using second_space::func;


void arr_rotate()
{
	int list[10] = {0,1,2,3,4,5,6,7,8,9};
	int from = 0;
	int val = list[from];
	int n= 10;
	int m = 3;
	int j;

	printf ("\noriginal array : ");
	for (j = 0; j < n; j++)
	{
		printf ("\t%d", list[j]);
	}

	for(int i = 0; i < n; i++)
	{
		int to = (((from - m) + n) % n);

		int temp = list[to];
		list[to] = val;
		val = temp;
		from = to;
	}

	printf ("\n\n\nfinal array : ");
	for (j = 0; j < n; j++)
	{
		printf ("\t%d", list[j]);
	}
	printf ("\n\n");
	return;
}


//int myfun(void);
extern "C"
{
	int myfun(void);
}

void print(int i) {
  cout << " Here is int " << i << endl;
}
void print(double  f) {
  cout << " Here is float " << f << endl;
}
void print(char* c) {
  cout << " Here is char* " << c << endl;
}

void combination(char **curString,int allowedStart,char **outBuffer,int length)
{
    //check for allowed chars.
    // if not return.
    // else
    // for each char in the allowed char
    // copy into buffer
    //print buffer
    //combine buffer and over next allowed chars
    //remove from buffer.
    int curr;

    if ( allowedStart == length )
        return;
    else    {

            for (curr = allowedStart;curr<length; curr++){
        //need to copy 'a' into outbuffer and keep appending to outbuffer.
        //      printf("allowedStart= %d  curr= %d \n",allowedStart,curr);

                (*outBuffer)[curr] = (*curString)[allowedStart];
                //adjust for appending.

                int i = 0;
                while (i < length)
                {
                    if ( ((*outBuffer)[i] == '\0') && ((*outBuffer)[i+1] != '\0') )
                    {
        //              printf("in here\n");
                        (*outBuffer)[i] = (*outBuffer)[i+1];
                        (*outBuffer)[i+1] = '\0';
                    }
                    i++;
                }

        //      printf("added curr%d %c \n",curr, (*outBuffer)[curr]);
                printf("***************************************COMBO: %s\n",*outBuffer);        
                allowedStart = curr+1;
        //      printf("allowedStart%d %c \n",allowedStart,(*curString)[allowedStart]);

                combination(curString,allowedStart,outBuffer,length);
        //      printf("removing%d %c\n",curr,(*outBuffer)[curr]);
                (*outBuffer)[curr] = ' ';   
        //      printf("**************RETURNCOMBO: %s\n",*outBuffer);       

        } //else
    } //for 
}


int main(void)
{
	//arr_rotate();
	//myfun();
	//const int a=0;
	//int *ptr = (int *)malloc(sizeof(int));
	//int *ptr2 = new (int);
	//printf("%d\n", sizeof('a'));	// This alone line prints 4 in c project (ascii value is 4 byte integer)

	//func(); // with "using namespace first_space;"
	// Calls function from first name space.
	//first_space::func();
	// Calls function from second name space.
	//second_space::func(); 
	
	//// Overloading !
	//print(10);
	//print(10.10);
	//print("ten");

	//int *ptr;
	//int &ref = *ptr;

    char *var = "abcd";
    int length = strlen(var);
    printf("length = %d\n",length);
//  printf("Intial word is %s\n",var);
    char *outBuffer = (char *)calloc ( (length+1) , sizeof (char));
    //bzero(outBuffer,length);
    combination(&var,0,&outBuffer,length);

	return 0;
}
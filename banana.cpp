#include<stdio.h>
 
struct State
{
	int monkey;  //-1:Monkey at A; 0:Monkey at B;  1:Monkey at C;
	int box;	//-1:box at A; 0:box at B; 1:box at C;
	int banana;  //banana at B ,banana = 0;
	int monbox;	//-1:monkey on the box
};
 
struct State States[150];
char* routesave[150];
 
//monkey goto , monkey go to other place
void monkeygoto(int b,int i)
{
	int a;
	a = b;
	if(a == -1)
	{
		routesave[i] = "Monkey go to A";
		States[i+1] = States[i];
		States[i+1].monkey = -1;
	}
	else if(a == 0)
	{
		routesave[i] = "Monkey go to C";
		States[i+1] = States[i];
		States[i+1].monkey = 0;
	}
	else if(a ==1)
	{
		routesave[i] = "Monkey go to B";
		States[i+1] = States[i];
		States[i+1].monkey = 1;
	}
	else
	{
		printf("Wrong!");
	}
}
 
void movebox(int a,int i)
{
	int B;
	B=a;
	if(B== -1)
	{
		routesave[i] = "monkey move box to A";
		States[i+1] = States[i];
		States[i+1].monkey = -1;
		States[i+1].box=-1;
	}
	else if(B==0)
	{
		routesave[i] = "monkey move box to C";
		States[i+1] = States[i];
		States[i+1].monkey = 0;
		States[i+1].box= 0;
	}
	else if(B==1)
	{
		routesave[i] = "monkey move box to B";
		States[i+1] = States[i];
		States[i+1].monkey = 1;
		States[i+1].box= 1;
	}
	else
	{
		printf("Wrong!");
	}
}
 
void climbonto(int i)
{
	routesave[i] = "monkey climb onto box";
	States[i+1] = States[i];
	States[i+1].monbox = 1;
}
 
void climbdown(int i)
{
	routesave[i] = "monkey climb down box";
	States[i+1] = States[i];
	States[i+1].monbox = -1;
}
 
void reach(int i)
{
	routesave[i] = "monkey reach the banana";
}
 
void showSolution(int i)
{
	int c;
	printf("%s \n","Result to problem:");
	for(c=0;c<i+1;c++)
	{
		printf("Step %d : %s \n",c+1,routesave[c]);
	}
	printf("\n");
}
 
void nextStep(int i)
{
	int c;
	int j;
	if(i>=100)
	{
		printf("step has reached 100,Wrong!");
		return;
	}
	for(c=0;c<i;c++)
	{
		if(States[c].monkey == States[i].monkey && States[c].box == States[i].box && States[c].banana == States[i].banana && States[c].monbox == States[i].monbox)
		{
			return;
		}
	}
	if(States[i].monbox == 1 && States[i].monkey == 0 && States[i].banana == 0 && States[i].box == 0)
	{
		showSolution(i);
		printf("end");
		while(1)
			getchar();
		return;
	}
	j = j + 1;
	if(States[i].monkey==0)
	{
		if(States[i].box == 0)
		{
			if(States[i].monbox == -1)
			{
				climbonto(i);
				reach(i+1);
				nextStep(j);
			}
			else
			{
				reach(i+1);
				nextStep(j);
			}
		}
		else if(States[i].box == 1)
		{
			monkeygoto(1,i);
			nextStep(j);
			movebox(0,i);
			nextStep(j);
			climbonto(i);
			reach(i+1);
			nextStep(j);
		}
		else	//box = -1
		{
			monkeygoto(-1,i);
			nextStep(j);
			movebox(0,i);
			nextStep(j);
			climbonto(i);
			reach(i+1);
			nextStep(j);
		}
	}
	if(States[i].monkey== -1)
	{
		if(States[i].box ==  -1)
		{
			if(States[i].monbox == -1)
			{
				movebox(0,i);	
				nextStep(j);
				climbonto(i);
				reach(i+1);
				nextStep(j);
			}
			else
			{
				climbdown(i);
				nextStep(j);
				movebox(0,i);
				nextStep(j);
				climbonto(i);
 
				reach(i+1);
				nextStep(j);
			}
		}
		else if(States[i].box == 0)
		{
			monkeygoto(0,i);
			nextStep(j);
			
			climbonto(i);
			reach(i+1);
			nextStep(j);
		}
		else	
		{
			monkeygoto(1,i);
			nextStep(j);
			movebox(0,i);
			nextStep(j);
			climbonto(i);
			reach(i+1);
			nextStep(j);
		}
	}
 
	if(States[i].monkey== 1)
	{
		if(States[i].box ==  1)
		{
			if(States[i].monbox == -1)
			{
				movebox(0,i);	
				nextStep(j);
				climbonto(i);
				reach(i+1);
				nextStep(j);
			}
			else
			{
				climbdown(i);
				nextStep(j);
				movebox(0,i);
				nextStep(j);
				climbonto(i);
 
				reach(i+1);
				nextStep(j);
			}
		}
		else if(States[i].box == -1)
		{
			monkeygoto(-1,i);
			nextStep(j);
			movebox(0,i);
			nextStep(j);
			movebox(0,i);
			nextStep(j);
			climbonto(i);
			reach(i+1);
			nextStep(j);
		}
		else	
		{
			monkeygoto(0,i);
			nextStep(j);
			movebox(0,i);
			nextStep(j);
			climbonto(i);
			reach(i+1);
			nextStep(j);
		}
	}
 
 
}
 
int main()
{
	int q,p,k;
	printf(" -1:A, 1:B ,0:C,  enter the location of monkey , box, banana:\n"); 
	scanf("%d%d%d",&q,&p,&k);
	States[0].monkey = q;
	States[0].box = p;
	States[0].banana = k;
	States[0].monbox = -1;
	nextStep(0);
}

#include<stdio.h>

#define a 100
#define b 100
int main(void){

  int H,W;
  int count=0;
  int i;
  int current_h=0,current_w=0;
  int before_h=1,before_w=1;
  scanf("%d %d",&H,&W);
  char s[a][b];

  for(i=0;i<H;i++){
    scanf("%s",s[i]);
  }
  
  while(1){
    count++;
    if(H==1&&W==1)
      break;

    if(count==1){
      if(s[current_h][current_w]=='/')
      break;
      else if(s[current_h][current_w]=='_'){
	before_w=current_w;
	before_h=current_h;
	current_w++;
      }
      else if(s[current_h][current_w]=='\\'){
	before_h=current_h;
	before_w=current_w;      
	current_h++;
      }
    }
    else{
      if(before_w<current_w){        //右に進む
	if(s[current_h][current_w]=='_'){
	  before_w=current_w;
	  before_h=current_h;
	  current_w++;
	}
	else if(s[current_h][current_w]=='/'){
	  before_w=current_w;
	  before_h=current_h;
	  current_h--;
	}
	else if(s[current_h][current_w]=='\\'){
	  before_h=current_h;
	  before_w=current_w;
	  current_h++;
	}
	if(current_w==W||current_h<0||current_h==H)
	  break;
      }
      
      else if(before_w>current_w){     //左
	if(s[current_h][current_w]=='_'){
          before_w=current_w;
          before_h=current_h;
          current_w--;
        }
	else if(s[current_h][current_w]=='/'){
          before_w=current_w;
          before_h=current_h;
          current_h++;
        }
        else if(s[current_h][current_w]=='\\'){
          before_h=current_h;
          before_w=current_w;
          current_h--;
	}
        if(current_w<0||current_h==H||current_h<0)
          break;
      }
      
      else if(before_h>current_h){   //上に進む
	if(s[current_h][current_w]=='_'){
          before_w=current_w;
          before_h=current_h;
          current_h--;
        }
        else if(s[current_h][current_w]=='/'){
          before_w=current_w;
          before_h=current_h;
          current_w++;
        }
        else if(s[current_h][current_w]=='\\'){
          before_h=current_h;
          before_w=current_w;
          current_w--;
        }
        if(current_w<0||current_w==W||current_h<0)
          break;
      }
      
      else if(before_h<current_h){
	
	if(s[current_h][current_w]=='_'){
          before_w=current_w;
          before_h=current_h;
          current_h++;
        }
        else if(s[current_h][current_w]=='/'){
          before_w=current_w;
          before_h=current_h;
          current_w--;
        }
        else if(s[current_h][current_w]=='\\'){
          before_h=current_h;
          before_w=current_w;
          current_w++;
        }
        if(current_w<0||current_h==H||current_w==W)
          break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

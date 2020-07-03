#include "../include/common/data.h"
#include<math.h>
#include <stdio.h>
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  unsigned int Sign_flag=0;
  unsigned int i;
  int32_t x;
  uint8_t length;
  if(base <2 || base>16)
  {
    return 0;
  }
  if(data<0)
  {
    data=data*-1;
    Sign_flag=1;
  }
  x=data;
  do
  {
    x=x/base;
    length++;
  }

  while(x!=0);
  for(i=0;i<length;i++)
  {
    if((data%base)<10)
      *(ptr+length-i-1+Sign_flag)=((data%base)+48);
    else
      *(ptr+length-i-1+Sign_flag)=((data%base)+55);
    data=data/base;
  }
  if(Sign_flag==1)
  {
   *(ptr)='-';
   length++;
  }
  *(ptr+length)='\0';
  return (length+1);
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  int32_t result=0;
  unsigned int i;
  unsigned int Sign_flag=0;
  if(base<2 || base>16)
  {
    return 0;
  }
  if(*(ptr)=='-')
  {
    Sign_flag=1;
  }

  for(i=0;i<digits-Sign_flag-1;i++)
  {
    if(*(ptr+digits-i-2)<65)
      result=result+((*(ptr+digits-i-2)-48)*pow(base,i));

    else
      result=result+((*(ptr+digits-i-2)-55)*pow(base,i));

}
  if(Sign_flag==1)
  {
    result=result*-1;
  }

  return result;
}

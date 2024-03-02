/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitNumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:21:39 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/02 05:33:22 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long convertint(char *str)
{
    int i;
    long  r;
    int s;
    
    i = 0;
    s = 1;
    r = 0;
    if (str[i] == '+' || str[i]== '-')
    {
        if (str[i] == '-')
            s *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        r *= 10;
        r += str[i++] - 48;
        if ((r > 2147483647 && s == 1) || (r < -2147483648 && s == -1))
            return (2147483648);
    }
    return (r * s);
}
int countnumber(char *s)
{
    int v[3];
    
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    while(s[v[1]])
    {
        if(s[v[1]] == ' ')
            v[2] = 0;
        else if (!v[2])
        {
            v[2] = 1;
            v[0]++;
        }
        v[1]++;
    }
    return (v[0]);
}
char *get_number(char *s ,int *s1)
{
  int i = 0;
  int c = 0;
  char *r;
    while(s[i] == ' ')
      i++;
    while(s[i] != ' ' && s[i])
    {
      i++;
      c++;      
    }
  r = malloc(c+1);
  i = 0;
  c = 0;
  while(s[i] == ' ')
      i++;
    while(s[i] != ' ' && s[i])
    {
        r[c++] = s[i++];  
    }
    r[c] = 0;
    *s1 = i;
    return r;
}
char **splitspase(char *s ,int *len)
{
  char  **r;
  int  i = 0;
  int  g = countnumber(s);
  int c = 0;
  r = (char **)malloc((g + 1) * sizeof(char *));
  while(i < g){
    r[i] = get_number(s,&c);
    s += c;
    i++;
  }
  r[g] = 0;
  *len = g;
  return r;
}
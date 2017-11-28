package program_edit_kata;

import java.util.*;
import java.util.Scanner;

public class Program_edit_kata 
{
    public static void main(String[] args) 
    {
       int i,active=-1,tail=-1,index;
       LinkedList<String> linkedlist = new LinkedList<>();
       Scanner inp = new Scanner(System.in);
       System.out.print("Jumlah inputan : ");
       for(i=inp.nextInt();i>0;i--)
       {
           
           System.out.println("1. Print\n2. Add\n3. Delete\n4. Shift Left\n5. Shift Right");
           System.out.print("Pilihan : ");
           switch(inp.nextInt())
           {
               case 1 : 
               {
                   if(tail>-1)
                   {
                       index=0;
                       while(index<=tail) System.out.print(""+linkedlist.get(index++));
                       System.out.println("");
                   }                   
               }break;
               case 2 : 
               {
                   System.out.print("Word : ");
                   linkedlist.add(++active,inp.next());
                   tail++;
               }break;
               case 3 : 
               {
                   if(tail>-1)
                   {
                       linkedlist.remove(active);
                       tail--;
                       if(active>0) active--;
                       else if(tail==-1) active=tail;
                   }
               }break;
               case 4 : 
               {
                   if(active>0) active--;
               }break;
               case 5 : 
               {
                   if(active<tail) active++;
               }break;
           }
       }
    }
}

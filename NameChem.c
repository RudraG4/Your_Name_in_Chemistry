#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<ansi.h>
#define n_array_1 (sizeof(Chem_Elem_1)/sizeof(const char *))
#define n_array_2 (sizeof(Chem_Elem_2)/sizeof(const char *))
void Chem_Name_Func(char word[]);
int Elem_1(char a,char buff[],int i);
int Elem_2(char a,char b,char buff[],int i);
void Createwindow();
char Chem_Sym[50]={'\0'};
char Chem_Elem_Name[100];
char buff[3]={'\0'};
bool status_1=true,status_2=false;
const char *Chem_Elem_1[]={"W","K","Hydrogen ","Boron ","Carbon ","Nitrogen ","Oxygen ","Fluorine ","Palladium ","Sulfur ","Vanadium ","Yttrium ","Iodine ","Uranium "};
const char *Chem_Elem_2[]={"Na","Mg","Cl","Cr","Mn","Fe","Cu","Zn","As","Rb","Sr","Zr","Nb","Tc","Pd","Ag","Cd","Sn","Sb","Cs","Nd","Pm","Sm","Gd","Tb",
"Tm","Yb","Hf","Re","Pt","Au","Hg","Tl","Pb","At","Rn","Pa","Np","Pu","Cm","Bk","Cf","Es","Fm","Md","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn",
"Helium ","Lithium ","Berillium ","Neon ","Aluminium ","Silicon ","Argon ","Calcium ","Scandium ","Titanium ","Cobalt ","Nickel ","Gallium ",
"Germanium ","Selenium ","Bromine ","Krypton ","Molybdenium ","Ruthenium ","Rhodium ","Indium ","Tellurium ","Xenon ","Barium ",
"Lanthanum ","Cerium ","Praseodymium ","Europium ","Dysprosium ","Holmium ","Erbium ","Lutetium ","Tantalum ","Osmium ","Iridium ","Bismuth ",
"Polonium ","Francium ","Radium ","Actinium ","Thorium ","Americium ","Nobelium ","Flerovium "};

int main()
{
    int i,j,stlen;
    char Name[50],word[50];
    Createwindow();
    GOTOXY(34,2);
    puts("Spelling With Chemistry\n");
    GOTOXY(23,5);
    printf("Enter a name:\n");
    GOTOXY(23,7);
    gets(Name);
    GOTOXY(23,9);
    puts("Your Name in Chemistry:\n");
    stlen=strlen(Name);
    i=0;j=0;
    while(i<stlen)
    {
        if(!isalpha(Name[i]))
        {
            GOTOXY(23,11);
            puts("Enter an alphabetical name\n");
            puts("\n\n");
            exit(0);
        }
        else if(Name[i]==' ')
        {
            word[j]='\0';
            memset(buff,'\0',sizeof(buff));
            Chem_Name_Func(word);
            i++;j=0;
            memset(word,'\0',sizeof(word));
        }
        else
        {
            word[j++]=Name[i++];
            if(i==stlen)
            {
                word[j]='\0';
                memset(Chem_Sym,'\0',sizeof(Chem_Sym));
                memset(buff,'\0',sizeof(buff));
                Chem_Name_Func(word);
            }
        }
    }
  return EXIT_SUCCESS;
}
void Chem_Name_Func(char word[])
{
    int i=0;
    int wrdlen=strlen(word);
    while(i<wrdlen)
    {
      i=Elem_2(word[i],word[i+1],buff,i);
      memset(buff,'\0',sizeof(buff));
      if(!status_2)
      {
          i=Elem_1(word[i],buff,i);
          memset(buff,'\0',sizeof(buff));
      }
      if(status_1==false&&status_2==false)
      {
          GOTOXY(23,11);
          puts("Couldnt create a complete chemical name\n\n\n");
          exit(0);
      }
  }
  GOTOXY(23,11);
  printf("%s\n",Chem_Sym);
  GOTOXY(22,13);
  printf("%s\n\n",Chem_Elem_Name);
}
int Elem_1(char a,char buff[],int i)
{
    int j=0;
    if(islower(a))
        buff[0]=toupper(a);
    else
        buff[0]=a;
    for(j=0;j<n_array_1;j++)
    {
           if(!strncmp(buff,Chem_Elem_1[j],1) )
           {
               strcat(Chem_Sym,buff);
               strcat(Chem_Sym," ");
                switch(Chem_Elem_1[j][1])
               {
                case 'K': strcat(Chem_Elem_Name,"Potassium ");
                            break;
                case 'W':strcat(Chem_Elem_Name,"Tungsten ");
                            break;
                default: strcat(Chem_Elem_Name,Chem_Elem_1[j]);
               }
               status_1=true;
               return (i+1);
           }
    }
   status_1=false;
   return i;
}
int Elem_2(char a,char b,char buff[],int i)
{
    int j;
    if(islower(a))
        buff[0]=toupper(a);
    else buff[0]=a;
    if(isupper(b))
        buff[1]=tolower(b);
    else
        buff[1]=b;
    for(j=0;j<n_array_2;j++)
    {
           if(!strncmp(buff,Chem_Elem_2[j],2))
           {

               strcat(Chem_Sym,buff);
               strcat(Chem_Sym," ");
                if(j<54)
                {
                    switch(j){
                    case 0: strcat(Chem_Elem_Name,"Sodium ");
                            break;
                    case 1: strcat(Chem_Elem_Name,"Magnesium ");
                            break;
                    case 2: strcat(Chem_Elem_Name,"Chlorine ");
                            break;
                    case 3: strcat(Chem_Elem_Name,"Chromium ");
                            break;
                    case 4: strcat(Chem_Elem_Name,"Manganese ");
                            break;
                    case 5: strcat(Chem_Elem_Name,"Iron ");
                            break;
                    case 6: strcat(Chem_Elem_Name,"Copper ");
                            break;
                    case 7: strcat(Chem_Elem_Name,"Zinc ");
                            break;
                    case 8: strcat(Chem_Elem_Name,"Arsenic ");
                            break;
                    case 9: strcat(Chem_Elem_Name,"Rubidium ");
                            break;
                    case 10: strcat(Chem_Elem_Name,"Strontium ");
                            break;
                    case 11: strcat(Chem_Elem_Name,"Zirconium ");
                            break;
                    case 12: strcat(Chem_Elem_Name,"Niobium ");
                            break;
                    case 13: strcat(Chem_Elem_Name,"Technetium ");
                            break;
                    case 14: strcat(Chem_Elem_Name,"Palladium ");
                            break;
                    case 15: strcat(Chem_Elem_Name,"Silver ");
                            break;
                    case 16: strcat(Chem_Elem_Name,"Cadmium ");
                            break;
                    case 17: strcat(Chem_Elem_Name,"Tin ");
                            break;
                    case 18: strcat(Chem_Elem_Name,"Antimony ");
                            break;
                    case 19: strcat(Chem_Elem_Name,"Cesium ");
                            break;
                    case 20: strcat(Chem_Elem_Name,"Neodymium ");
                            break;
                    case 21: strcat(Chem_Elem_Name,"Promethium ");
                            break;
                    case 22: strcat(Chem_Elem_Name,"Samarium ");
                            break;
                    case 23: strcat(Chem_Elem_Name,"Gadolinium ");
                            break;
                    case 24: strcat(Chem_Elem_Name,"Terbium ");
                            break;
                    case 25: strcat(Chem_Elem_Name,"Thulium ");
                            break;
                    case 26: strcat(Chem_Elem_Name,"Ytterbium ");
                            break;
                    case 27: strcat(Chem_Elem_Name,"Hafnium ");
                            break;
                    case 28: strcat(Chem_Elem_Name,"Rhenium ");
                            break;
                    case 29: strcat(Chem_Elem_Name,"Platinum ");
                            break;
                    case 30: strcat(Chem_Elem_Name,"Gold ");
                            break;
                    case 31: strcat(Chem_Elem_Name,"Mercury ");
                            break;
                    case 32: strcat(Chem_Elem_Name,"Thallium ");
                            break;
                    case 33: strcat(Chem_Elem_Name,"Lead ");
                            break;
                    case 34: strcat(Chem_Elem_Name,"Astatine ");
                            break;
                    case 35: strcat(Chem_Elem_Name,"Radon ");
                            break;
                    case 36: strcat(Chem_Elem_Name,"Protactium ");
                            break;
                    case 37: strcat(Chem_Elem_Name,"Neptium ");
                            break;
                    case 38: strcat(Chem_Elem_Name,"Plutonium ");
                            break;
                    case 39: strcat(Chem_Elem_Name,"Curium ");
                            break;
                    case 40: strcat(Chem_Elem_Name,"Berkelium ");
                            break;
                    case 41: strcat(Chem_Elem_Name,"Californium ");
                            break;
                    case 42: strcat(Chem_Elem_Name,"Einsteinium ");
                            break;
                    case 43: strcat(Chem_Elem_Name,"Fermium ");
                            break;
                    case 44: strcat(Chem_Elem_Name,"Mendelvium ");
                            break;
                    case 45: strcat(Chem_Elem_Name,"Lawrencium ");
                            break;
                    case 46: strcat(Chem_Elem_Name,"Rutherfodium ");
                            break;
                    case 47: strcat(Chem_Elem_Name,"Dubnium ");
                            break;
                    case 48: strcat(Chem_Elem_Name,"Seaborgium ");
                            break;
                    case 49: strcat(Chem_Elem_Name,"Bohrium ");
                            break;
                    case 50: strcat(Chem_Elem_Name,"Hassium ");
                            break;
                    case 51: strcat(Chem_Elem_Name,"Meitnerium ");
                            break;
                    case 52: strcat(Chem_Elem_Name,"Darmstadium ");
                            break;
                    case 53: strcat(Chem_Elem_Name,"Roentgenium ");
                            break;
                    case 54: strcat(Chem_Elem_Name,"Copernicium ");
                            break;
                    }

                }
                else
                        strcat(Chem_Elem_Name,Chem_Elem_2[j]);
               status_2=true; i=i+2;
               return (i);
           }
    }
   status_2=false;
   return i;
}
void Createwindow()
{
    int i;
    GOTOXY(18,2);
    printf("+---------------------------------------------------+\n");
    for(i=3;i<15;i++)
    {
         GOTOXY(18,i);
         printf("|                                                   |\n");
    }
    GOTOXY(22,6);
        printf("+----------------------------------------+\n");
    GOTOXY(22,7);
        printf("|                                        |");
    GOTOXY(22,8);
        printf("+----------------------------------------+\n");
    GOTOXY(22,10);
        printf("+----------------------------------------+\n");
    GOTOXY(22,11);
        printf("|                                        |");
    GOTOXY(22,12);
        printf("+----------------------------------------+\n");
    GOTOXY(18,i);
    printf("+---------------------------------------------------+\n");
}

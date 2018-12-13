#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef int bool;
#define TRUE 1
#define FALSE 0
typedef struct element
{
int info;
struct element *svt;
}liste;
liste *tete = NULL;
liste *creer_lcc(liste *);
liste *creer_lcc_LIFO(liste *);
liste *Afficher(liste *);
liste *insert_deb(liste *);
liste *insert_fin(liste *);
liste *supp_deb(liste *);
liste *supp_fin(liste *);
liste *supp_apres(liste *);
liste *supp_liste(liste *);
bool recherche(liste *);
int main()
{
int option;
clrscr();
do
{
printf("\n\n ****MENU PRINCIPALE*****");
printf("\n 1: Créer la liste FIFO");
printf("\n 2: Afficher la liste");
printf("\n 3: Ajouter un noeud au début de la liste");
printf("\n 4: Ajouter un noeud à la fin de la liste");
printf("\n 5: Supprimer un noeud au début de la liste ");
printf("\n 6: Supprimer un noeud à la fin de la liste ");
printf("\n 7: Supprimer un noeud après un noeud");
printf("\n 8: Supprimer toute la liste");
printf("\n 9: Créer la liste LIFO");
printf("\n 10: Rechercher une valeur dans une liste");
printf("\n 11: Sortir");
printf("\n\n Entrez votre choix : ");
scanf("%d", &option);
switch(option)
{
case 1: tete = creer_lcc(tete);
printf("\n La liste circulaire a étais créer");
break;
case 2: tete = Afficher(tete);
break;
case 3: tete = insert_deb(tete);
break;
case 4: tete = insert_fin(tete);
break;
case 5: tete = supp_deb(tete);
break;
case 6: tete = supp_fin(tete);
break;
case 7: tete = supp_apres(tete);
break;
case 9: tete = creer_lcc_LIFO(tete);
break;
case 8: tete = supp_liste(tete);
printf("\n Liste circulaire supprimer");
break;
case 10: if (recherche(tete)==TRUE) printf("\nle nombre existe");else printf("\n le nombre n'existe pas");
break;
}
}while(option !=11);
getch();
return 0;
}
liste * creer_lcc(liste *tete)
{
liste *new_node, *ptr;
int num;
printf("\n Entez –1 pour finir la création de la liste");
printf("\n Entrez une valeur : ");
scanf("%d", &num);
while(num!=-1)
{
new_node = (liste*)malloc(sizeof(liste));
new_node -> info = num;
if(tete == NULL)
{
new_node -> svt = new_node;
tete = new_node;
}
else
{ ptr = tete;
while(ptr -> svt != tete)
ptr = ptr -> svt;
ptr -> svt = new_node;
new_node -> svt = tete;
}
printf("\n Entrez une valeur : ");
scanf("%d", &num);
}
return tete;
}
bool recherche(liste *tete)
{
liste *p;
int val;
printf("\n Entrez la valeur rechercher :");
scanf("%d",&val);
p= tete;
while(p->svt!=tete)
{ if (p->info==val) return (TRUE);
p=p->svt;}
return (FALSE);
}
liste * creer_lcc_LIFO(liste *tete)
{
liste *new_node, *ptr;
int num;
printf("\n Entez –1 pour finir la création de la liste");
printf("\n Entrez une valeur : ");
scanf("%d", &num);
while(num!=-1)
{
new_node = (liste*)malloc(sizeof(liste));
new_node -> info = num;
if(tete == NULL)
{
new_node -> svt = new_node;
tete = new_node;
}
else
{ ptr = tete;
while(ptr -> svt != tete)
ptr = ptr -> svt;
ptr -> svt = new_node;
new_node -> svt = tete;
tete=new_node;
}
printf("\n Entrez une valeur : ");
scanf("%d", &num);
}
return tete;
}
liste * Afficher(liste *tete)
{
liste *ptr;
ptr=tete;
while(ptr -> svt != tete)
{
printf("\t %d", ptr -> info);
ptr = ptr -> svt;
}
printf("\t %d", ptr -> info);
return tete;
}
liste *insert_deb(liste *tete)
{
liste *new_node, *ptr;
int num;
printf("\n Enter the info : ");
scanf("%d", &num);
new_node = (liste *)malloc(sizeof(liste));
new_node -> info = num;
ptr = tete;
while(ptr -> svt != tete)
ptr = ptr -> svt;
ptr -> svt = new_node;
new_node -> svt = tete;
tete = new_node;
return tete;
}
liste *insert_fin(liste *tete)
{
liste *ptr, *new_node;
int num;
printf("\n Entez la donnée: ");
scanf("%d", &num);
new_node = (liste *)malloc(sizeof(liste));
new_node -> info = num;
ptr = tete;
while(ptr -> svt != tete)
ptr = ptr -> svt;
ptr -> svt = new_node;
new_node -> svt = tete;
return tete;
}
liste *supp_deb(liste *tete)
{
liste *ptr;
ptr=tete;
while(ptr -> svt != tete)
ptr = ptr -> svt;
ptr -> svt = tete -> svt;
free(tete);
tete = ptr -> svt;
return tete;
}
liste *supp_fin(liste *tete)
{
liste *ptr, *preptr;
ptr = tete;
while(ptr -> svt != tete)
{
preptr = ptr;
ptr = ptr -> svt;
}
preptr -> svt = ptr -> svt;
free(ptr);
return tete;
}
liste *supp_apres(liste *tete)
{
liste *ptr, *preptr;
int val;
printf("\n Enterez la valeur du noeud que nous devons suprimer aprés: ");
scanf("%d", &val);
ptr = tete;
preptr = ptr;
while(preptr -> info != val)
{
preptr = ptr;
ptr = ptr -> svt;
}
preptr -> svt = ptr -> svt;
if(ptr == tete)
tete = preptr -> svt;
free(ptr);
return tete;
}
liste *supp_liste(liste *tete)
{
liste *ptr;
ptr = tete;
while(ptr -> svt != tete)
tete = supp_fin(tete);
free(tete);
return tete;
}

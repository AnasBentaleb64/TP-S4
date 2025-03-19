#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATE{
    char jour[3];
    char mois[3];
    char annee[5];
}date;

typedef struct PRODUIT{
    char *nomP;
    char ref[100];
    float montant;
    date dachat;
}produit;

typedef struct LISTE{
    produit cellule;
    struct LISTE *suiv;
}liste;

liste* creer_liste_produits(){
    return NULL;
}

int est_vide(liste* debut){
    if (debut==NULL)
        return 1;
    else{
        return 0;
    }
}

liste* creer_produit(){
    liste *nv=(liste*)malloc(sizeof(liste));
    if(nv==NULL){
        printf("Erreur d'allocation");
        exit(0);
    }
    nv->suiv=NULL;
    printf("Veuillez saisir le nom du produit :");
    gets(nv->cellule.nomP);
    printf("Veuillez saisir la reference du produit :");
    gets(nv->cellule.ref);
    printf("Veuillez saisir le montant du produit :");
    scanf("%f",&nv->cellule.montant);
    printf("Veuillez saisir la date d'achat du produit :");
    printf("JOUR :");
    fgets(nv->cellule.dachat.jour,3,stdin);
    printf("MOIS :");
    fgets(nv->cellule.dachat.mois,3,stdin);
    printf("ANNEE :");
    fgets(nv->cellule.dachat.annee,5,stdin);
    return nv;

}

void afficher(produit* prod){

    if (prod==NULL)
        printf("Le produit n'existe pas .");
    else{
            printf("Le nom du produit est : %s",prod->nomP);
            printf("La reference du produit est : %s",prod->ref);
            printf("Le montant du produit est : %f",prod->montant);
            printf("La date de l'achat est :%s/%s/%s ",prod->dachat.jour,prod->dachat.mois,prod->dachat.annee);

    }
}

liste* ajoutD(liste* debut){
    liste* nv=creer_produit();
    if (debut==NULL)
        debut=nv;
    else{
        nv->suiv=debut;
        debut=nv;
    }
    return debut;
}

void ajoutF(liste*debut){
    liste* ptr=debut;
    liste*nv=creer_produit();
    if(debut==NULL)
        return ;
    else{
        while(ptr->suiv!=NULL){
            ptr=ptr->suiv;
        }
        ptr->suiv=nv;
    }

}



void afficher_produit_liste(liste *debut){
    liste *ptr=debut;
    while(ptr!=NULL){
        afficher_produit(ptr);
        ptr=ptr->suiv;
    }
}

int longueur(liste *debut){
    int c=0;
    liste *ptr=debut;
    for(ptr=debut;ptr!=NULL;ptr=ptr->suiv){
        c++;
    }
    return c;
}

void filtrer_date(liste *debut, date d){
    liste *ptr=debut;
    while(ptr!=NULL){
        if(strcmp(ptr->cellule.date_achat.jour, d.jour) == 0 && strcmp(ptr->cellule.date_achat.mois, d.mois) == 0 && strcmp(ptr->cellule.date_achat.annee, d.annee) == 0){
            afficher_produit(ptr);
        }
        ptr=ptr->suiv;
    }
}

liste *suppD_liste(liste *debut){
    liste *ptr=debut;
    if(est_vide(debut)==1){
        printf("La liste est vide\n");
        return debut;
    }
    else{
        debut=debut->suiv;
        free(ptr);
        return debut;
    }
}

liste *suppF_liste(liste *debut){
    liste *ptr=debut;
    if(est_vide(debut)==1){
        printf("La liste est vide\n");
    }
    else{
        while(ptr->suiv->suiv!=NULL){
            ptr=ptr->suiv;
        }
        free(ptr->suiv);
        ptr->suiv=NULL;
    }
}

liste *rembourser_produit(liste *debut, char *ref){
    liste *ptr=debut->suiv;
    int i=0;
    liste *temp=ptr;
    if(strcmp(debut->cellule.ref, ref) == 0){
        suppD_liste(debut);
    }
    else{
        while(ptr!=NULL){
            ptr=ptr->suiv;
            i++;
        }
        if(i==longueur(debut)){
            printf("Le produit n'existe pas\n");
        }
        else{
            for(int j=0;j<i-1;j++){
                temp=temp->suiv;
            }
            temp->suiv=temp->suiv->suiv;
            free(ptr);
        }
    }

}

int main()
{

}

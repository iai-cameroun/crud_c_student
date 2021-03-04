//
// Créé par IAI-Cameroun le 03/03/2021.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>

#define Student struct Stud

void add(FILE * fp);
void modify(FILE * fp);
void display(FILE * fp);
void Indivisual(FILE *fp);
void password();
FILE * del(FILE * fp);
void printChar(char ch,int n);
void title();
FILE *tp;

void gotoxy(int x,int y)
{
	COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

struct pass
{
	char pass[25];
}pa;

struct Stud
{
    char name[100];
    char dept[50];
    int roll;
    float sgpa[12];
    float cgpa;
};


int main()
{
    int ch,id,i;
    int k =0;
    char c,pas[50];
    SetConsoleTitle("SYSTEME DE GESTION ETUDIANT | IAI");
    FILE * fp;
    Student s;
    int option;
    char another;

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        if((fp=fopen("db.txt","wb+"))==NULL)
        {
            printf("Impossible d'ouvrir ou de créer la BD.");
            return 0;
        }
    }
    system("color 9f");
	gotoxy(42,8);
	printf("CONNEXION(SI vous etes à votre premiere connexion appuyez sur ENTRER)");
	gotoxy(42,10);
	printf("____________________________________");
	gotoxy(42,11);
	printf("|\tEntrer le mot de passe :             |");
	gotoxy(42,12);
	printf("|__________________________________|");
	//printf("\n\t\t\t\t\t");
	gotoxy(65,11);
	while( k<10)
	{
	    pas[k]=getch();
	    char s=pas[k];
	    if(s==13)
		 break;
	    else printf("*");
	    k++;
	}
	pas[k]='\0';
	tp=fopen("C:/Password.txt","r+");
    fgets(pa.pass,25,tp);
    if(strcmp(pas,pa.pass)==0)
	{
		system("cls");
		gotoxy(10,3);
		printf("<<<< Chargement, veuillez patienter >>>>");
		for(i=0; i<5; i++)
        {
            printf("\t(*_*)");
            Sleep(500);
        }
        printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *       Bienvenue      *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\n\n\n\t\t\t\t\tAppuyez sur une touche pour continuer...... ");
		getch();

    title();
    printf("\n\n\t\t\t\tDDTCNC");
    printf("\n\n\t\t\t\t     L'équipe");
    printf("\n\n\t\t\t  IAI-Cameroun\n\t\t\t");
    printChar('=',38);
    printf("\n\n\n\t\t\t       Appuyez sur une touche pour continuer");
    getch();

    while(1)
    {
        title();
        printf("\n\t");
        printChar('*',64);

        printf("\n\n\t\t\t\t1. Ajouter un étudiant");
        printf("\n\n\t\t\t\t2. Modifier un étudiant");
        printf("\n\n\t\t\t\t3. Afficher tous les étudiants");
        printf("\n\n\t\t\t\t4. Affichage individuel");
        printf("\n\n\t\t\t\t5. Supprimer un étudiant");
        printf("\n\n\t\t\t\t6. Modifier Mot de Passe");
        printf("\n\n\t\t\t\t7. Déconnexion\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\tEntrer votre choix :--> ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                add(fp);
                break;
            case 2:
                modify(fp);
                break;
            case 3:
                display(fp);
                break;
            case 4:
                Indivisual(fp);
                break;
            case 5:
                fp=del(fp);
                break;
            case 6:
                    system("cls");
				    system("color 5f");
			        password();
                break;
            case 7:
                return 1;
                break;
            default:
                printf("\n\t\tAucune action détectée");
                printf("\n\t\tAppuyez sur une touche\n\n\n");
                getch();
                system("pause");
        }
    }
    }
    else
    {
        printf("Mauvais mot de passe . Sortie");
        getch();
    }
    return 1;

}


void password()
{
	char c;
	printf("\nEntrer nouveau mot de passe :");
	fflush(stdin);
	gets(pa.pass);
	printf("\nSauvegarder Mot de Passe (y/n) :");
	fflush(stdin);
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		tp=fopen("C:/Password.txt","w+");
	    fwrite(&pa,sizeof(pa),1,tp);
	    fclose(tp);
		printf("\n\tMot de passe enregistré\n");
	}
	else
	{
		printf("Mot de passe non enregistré :\n");
		printf("Appuyez sur une touche pour continuer >>>");
		getch();
	}
}


void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

void title()
{
    system("cls");
    system("COLOR 03");
    printf("\n\n\t");
    printChar('=',19);
    printf(" GESTION DES ETUDIANTS ");
    printChar('=',19);
    printf("\n");
}


//Insérer à la fin

void add(FILE * fp)
{
    title();

    char another='y';
    Student s;
    int i;
    float cgpa;

    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {

        printf("\n\n\t\tEntrer le nom complet: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\tEnter Nom département: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\tEntrer le numéro: ");
        scanf("%d",&s.roll);

        printf("\n\n\tEntrer les 12 notes pour le semestre\n");
        for(i=0,cgpa=0; i<12; i++)
        {
            scanf("%f",&s.sgpa[i]);
            cgpa+=s.sgpa[i];

        }

        cgpa/=12.0;
        s.cgpa=cgpa;

        fwrite(&s,sizeof(s),1,fp);

        printf("\n\n\t\tAjouter un nouvel étudiant?(Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}


FILE * del(FILE * fp)
{
    title();

    Student s;
    int flag=0,tempRoll,siz=sizeof(s);
    FILE *ft;

    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERREUR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEntrer le numéro d'étudiant à supprimer");
    printf("\n\n\t\t\tRoll No. : ");
    scanf("%d",&tempRoll);

    rewind(fp);


    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            printf("\n\tEnregistrement supprimé");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.dept,s.roll);
            continue;
        }

        fwrite(&s,siz,1,ft);
    }


    fclose(fp);
    fclose(ft);

    remove("db.txt");
    rename("temp.txt","db.txt");

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        printf("ERREUR");
        return  NULL;
    }

    if(flag==0) printf("\n\n\t\tAUCUNE INFORMATION ETUDIANT TROUVEE\n\t");

    printChar('-',65);
    printf("\n\t");
    system("pause");
    return fp;
}


void modify(FILE * fp)
{
    title();

    Student s;
    int i,flag=0,tempRoll,siz=sizeof(s);
    float cgpa;

    printf("\n\n\tEntrer le numéro étudiant à modifier : ");
    scanf("%d",&tempRoll);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\n\n\t\t\t\tEnregistrement trouvé\n\t\t\t");
        printChar('=',38);
        printf("\n\n\t\t\tNom Etudiant: %s",s.name);
        printf("\n\n\t\t\tNuméro étudiant: %d\n\t\t\t",s.roll);
        printChar('=',38);
        printf("\n\n\t\t\tEntrer les nouvelles données");

        printf("\n\n\t\t\tEntrer le nom complet: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\t\tEntrer Département: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\t\tEntrer le numéro: ");
        scanf("%d",&s.roll);


        printf("\n\n\t\tEntrer les 12 notes pour le semestre (SGPA)\n");
        for(i=0,cgpa=0; i<12; i++)
        {
            scanf("%f",&s.sgpa[i]);
            cgpa+=s.sgpa[i];

        }
        cgpa=cgpa/8.0;


        fwrite(&s,sizeof(s),1,fp);
    }

    else printf("\n\n\t!!!! ERREUR !!!! ENREGISTREMENT NON TROUVE");

    printf("\n\n\t");
    system("pause");

}

void display(FILE * fp)
{
    title();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNOM : %s",s.name);
        printf("\n\n\t\tDépartement : %s",s.dept);
        printf("\n\n\t\tNuméro : %d",s.roll);
        printf("\n\n\tSGPA: ");

        for(i=0; i<12; i++)
            printf("| %.2f |",s.sgpa[i]);
        printf("\n\n\t\tCGPA : %.2f\n\t",s.cgpa);
        printChar('-',65);
    }
    printf("\n\n\n\t");
    printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

void Indivisual(FILE *fp)
{
    title();

    int tempRoll,flag,siz,i;
    Student s;
    char another='y';

    siz=sizeof(s);

    while(another=='y'||another=='Y')
    {
        printf("\n\n\tEntrer numéro étudiant: ");
        scanf("%d",&tempRoll);

        rewind(fp);

        while((fread(&s,siz,1,fp))==1)
        {
            if(s.roll==tempRoll)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\t\tNOM : %s",s.name);
            printf("\n\n\t\tDépartement : %s",s.dept);
            printf("\n\n\t\tNuméro : %d",s.roll);
            printf("\n\n\tSGPA: ");

            for(i=0; i<12; i++)
                printf("| %.2f |",s.sgpa[i]);
            printf("\n\n\t\tCGPA : %.2f\n\t",s.cgpa);
            printChar('-',65);

        }
        else printf("\n\n\t\t!!!! ERREUR ENREGISTREMENT NON TROUVE !!!!");


        printf("\n\n\t\tAfficher d'autres informations étudiants? (Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}

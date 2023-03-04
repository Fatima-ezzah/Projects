#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int taille=10;
int M[taille][taille];
int n,i,j;
float m;
cout << "Entrer le nombre des lignes: "<< endl;
cin >>m;
cout << "Entrer le nombre des colonnes: "<< endl;
cin >>n;
cout <<"Entrer les elements de la matrice: \n"<< endl;
for(i=0; i<m; i++){
		for(j=0; j<n; j++)
		{
			cout <<"\tElem [%d][%d]= "<<endl ;
			cin >>M[i][j];
		}
}
printf("\n La matrice est:\n");
for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			printf("%d\t",M[i][j]);
printf("\n");
}
printf("calcul des moyennes pour calculer l'ecart type \n");
int k=0,y[taille][taille];
float z[taille][taille],ecart[taille],somme=0,moyenne,si[taille],moy_carre,som_carre=0,mult,s[taille];
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
    somme+= M[j][i];
moyenne=somme/m ;
s[k]=moyenne;
for(j=0;j<m;j++){
mult=M[j][i]*M[j][i];
    som_carre+= mult;
}
moy_carre=som_carre/m ;
si[k]=moy_carre;
ecart[k]= sqrt(si[k]-s[k]*s[k]);
k++;
somme=0;
som_carre=0;
}printf("\n ");
/*La moyenne de chaque colonne:*/
for(k=0;k<n;k++){
printf("\n la moyenne de la colonne %d est: %f ",k+1,s[k]);
printf("\n l'ecart type de la colonne %d est: %f ",k+1,ecart[k]);
printf("\n");
}
/* matrice centrée et réduite*/
k=0;
while(k<n){
for(i=0;i<n;i++)
{for(j=0;j<m;j++){
/*matrice centrée*/
 y[j][i]=M[j][i] - s[k];
/*matrice réduite */

z[j][i]=y[j][i]/ ecart[k];
}printf("\n");k++;
}}
printf("\n la matrice centree est \n ");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
printf("%d\t", y[i][j]);
printf("\n");
}
printf("\n la matrice reduite est \n ");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
printf("%f\t", z[i][j]);
printf("\n");
}
printf(" calcul de la matrice de covariance_variance\n");
float z_transpose[taille][taille],R[taille][taille];int y_transpose[taille][taille];
float v[taille][taille];

for(i=0;i<m;i++)
{
for(j=0;j<n;j++){
    y_transpose[j][i]=y[i][j];
    z_transpose[j][i]=z[i][j];
}
}
printf("\n La matrice centree transposee est:\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
printf("%d\t", y_transpose[i][j]);
printf("\n");
}
printf("\n La matrice reduite transposee est:\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
printf("%f\t", z_transpose[i][j]);
printf("\n");
}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++){
v[i][j]=0;
R[i][j]=0;
    for(k=0;k<m;k++){
        v[i][j]= v[i][j]+ (1/m )* y_transpose[i][k] * y[k][j];
        R[i][j]=R[i][j] + (1/m )* z_transpose[i][k] * z[k][j];
    }
}
}
printf("\n la matrice de covariance\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++){
    printf("%f\t ",v[i][j]);
}
printf("\n");
}
printf("\n la matrice de correlation\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++){
    printf("%f\t ",R[i][j]);
}
printf("\n");
}
/* On utilise la matrice de correlation R pour trouver les valeurs propres et les vecteurs propres
dans une matrice R de (2*2) l'equation est de seconde degrée x^2 -2*x+(1-d^2) et delta=4-4c d'où c=1-d^2 donc delta=4*d^2*/
float a,b,c,delta,x0,x1,x2;
for(i=1;i<n;i++)
{
for(j=0;j<n-1;j++)
    c= 1 - R[i][j]*R[i][j];
    printf("le coefficient c de l'equation de seconde degree est: %f ",c);
}
delta= 4*c;
printf("\n delta =%f\n",delta);
if(delta==0) { /*x0=-b/2a  b=-2 et a=1 tjrs*/
        x0= 1;
cout << "Equation admet une valeur propre:"<< endl;
cout << "x0= "<<x0<< endl;
}
/* delta soit positive ou nulle car delta= 4-4*c=4-4*(1-d^2)= d^2 quelque soit d négative ou positive le delta est positive*/
else{
x1= (2-sqrt(delta))/2;
x2= (2+sqrt(delta))/2;
cout << "Equation admet deux valeurs propres:"<< endl;
cout << "x1= "<<x1<< endl;
cout << "x2= "<<x2<< endl;
}

/*Les vecteurs propres*/
if(delta==0){
    cout << "le systeme d'equation est\n"<< endl;
    for(i=1;i<n;i++){
for(j=0;j<n-1;j++){
    cout << (1-x0)<<"x"<<"+"<<R[i][j]<<"y"<<"="<<0 <<endl;
    cout << R[i][j]<<"x"<<"+"<<(1-x0)<<"y"<<"="<<0 <<endl;
}
}
cout <<"x = "<< - R[i][j] /(1-x0) <<"y" <<endl;
cout <<"Le vecteur propre est: "<< "("<<-R[i][j] /(1-x0)<<","<<1<<")"<<endl;
}
else{float d;
 cout << "le systeme d'equation pour la premiere valeur propre est\n"<< endl;
    for(i=1;i<n;i++){
for(j=0;j<n-1;j++){
    cout << (1-x1)<<"x"<<"+"<<(R[i][j])<<"y"<<"="<<0 <<endl;
    cout << R[i][j]<<"x"<<"+"<<(1-x1)<<"y"<<"="<<0 <<endl;
d= -R[i][j] /(1-x1);
printf("%f\n",d);
cout <<"x = "<< d <<"y" <<endl;
}
}
cout <<"Le vecteur propre est: "<< "("<< d<<","<<1<<")"<<endl;
cout << "le systeme d'equation pour la deuxieme valeur propre est\n"<< endl;
for(i=1;i<n;i++){
for(j=0;j<n-1;j++){
cout << (1-x2)<<"x"<<"+"<<(R[i][j])<<"y"<<"="<<0 <<endl;
cout << R[i][j]<<"x"<<"+"<<(1-x2)<<"y"<<"="<<0 <<endl;
d= -R[i][j] /(1-x2);
printf("%f\n",d);
cout <<"x = "<< d<<"y" <<endl;
}
}
cout <<"Le vecteur propre est: "<< "("<< d<<","<<1<<")"<<endl;
}
    return 0;
}

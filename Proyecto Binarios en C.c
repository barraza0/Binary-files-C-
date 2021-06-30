//Brenda Barraza
//Code::Blocks 20.03
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
#include <ctype.h>
struct FechadeVencimiento_b{
    char Mes_b[4];
    char Anio_b[1];
};
struct FechadeNacimiento_b{
    char Dia2_b[1];
    char Mes2_b[1];
    short int Anio2_b;
};
struct FechadeVencimiento{
    char Mes[4];
    char Anio[1];
};
struct FechadeNacimiento{
    char Dia2[1];
    char Mes2[1];
    short int Anio2;
};
struct binario{
    char Tratamiento[6];
    char PrimerNombre[13];
    char SegundoNombre[2];
    char Apellido[12];
    char NumeroTelefonico[10];
    char Email[44];
    char Direccion[24];
    char Ciudad[26];
    char Departamento[15];
    char CodigoPostal[6];
    char Ocupacion[81];
    char Compania[36];
    char TarjetadeCredito[11];
    char Numero[17];
    char CVV[4];
    struct FechadeVencimiento_b FechaVenc_b;
    struct FechadeNacimiento_b FechaNac_b;
    char Edad[1];
    char Sexo[10];
    char TipodeSangre[4];
    float Peso;
    float Altura;};
struct lid{
    char Tratamiento2[6];
    char PrimerNombre2[13];
    char SegundoNombre2[2];
    char Apellido2[12];
    char NumeroTelefonico2[10];
    char Email2[44];
    char Direccion2[24];
    char Ciudad2[26];
    char Departamento2[15];
    char CodigoPostal2[6];
    char Ocupacion2[81];
    char Compania2[36];
    char TarjetadeCredito2[11];
    char Numero2[17];
    char CVV2[4];
    struct FechadeVencimiento FechaVenc;
    struct FechadeNacimiento FechaNac;
    char Edad2[1];
    char Sexo2[10];
    char TipodeSangre2[4];
    float Peso2;
    float Altura2;
    struct lid *sig;
    struct lid *ant;
};
void ingresa_bin(struct binario *,struct lid **);
//void ingresa(struct lid **);
void lee(struct lid **);
void borra(struct lid **);
void busca(struct lid **);
//void modifica(struct lid **);
//void endat(struct lid **);
void impdat(struct lid *);

int main(){
FILE *archivo;int op;
struct binario Dat; struct lid *pr=NULL;
    archivo = fopen("Datos.bin", "rb+");
    fread (&Dat,sizeof(Dat),1,archivo);
    while(!feof(archivo)){
        ingresa_bin(&Dat,&pr);
    fread (&Dat,1,sizeof(Dat),archivo);
    }
    fclose (archivo);
    for(;;){
        while(op!=6){
            printf("1__agregar registro  \n2__modificar registro \n3__eliminar registro \n4__listar todos los registros \n5__listar conjunto seleccionado \n6__salir de la aplicacion \n:");
            fflush(stdin);
            scanf("%d",&op);
            switch(op){
            case 1: ingresa(&pr);break;
           // case 2: modifica(&pr);break;
            case 3: borra(&pr);break;
            case 4: lee(&pr);break;
            case 5: busca(&pr);break;
            case 6: exit(0);
            }
        }
    }
}
/*void ingresa(struct lid **p){
struct lid *act,*aux,*ant;
char b[12], b2[12],k;
int ret;

        aux=(struct lid *)malloc(sizeof(struct lid));
        if(aux){
            printf("\n\nIngrese los datos : \n\n");
            endat(&aux);
            if(!*p){
                *p=aux;
                aux->sig=NULL;
                aux->ant=NULL;
            }else{
            do{
                ant=*p;
                act=*p;
                strcpy(b2,aux->Apellido2);
                strcpy(b,act->Apellido2);
                printf("%s",b);
                printf("%s",b2);
                ret=strcmp(b,b2);
                if(ret<0){
                    ant=act;
                    act=act->sig;
                }
                if(!act){
                    ant->sig=aux;
                    aux->sig=NULL;
                    aux->ant=ant;
                }else if(ant==act){
                    *p=aux;
                    aux->sig=ant;
                    aux->ant=NULL;
                    ant->ant=aux;
                }else{
                    ant->sig=aux;
                    aux->sig=act;
                    aux->ant=ant;
                    act->ant=aux;
                }
            }while(aux);
            }
        }else{
            printf("\n\nNo hay memoria disponible\n\n\nPresione una tecla para continuar\n");
            getch();
            return;
        }

}*/
void lee(struct lid **p){
struct lid *aux=*p;
    while(aux){
        printf("\nLos datos son : \n\n");
        impdat(aux);
        aux=aux->sig;
        printf("\nPresione una tecla para continuar--------------------------------------------------------------------\n");
        getch();
    }
}
void busca(struct lid **p){
struct lid *aux;
char b[10], b2[10],k;
int ret;
        printf("\nIngrese sexo a buscar : ");
        fflush(stdin);
        scanf("%s",b);
        aux=*p;
    do{
        strcpy(b2,aux->Sexo2);
        fflush(stdin);
        ret = strcmp(b,b2);
        if(ret==0){
            impdat(aux);
            aux=aux->sig;
            strcpy(b2,aux->Sexo2);
            ret = strcmp(b,b2);
            printf("\n\nPresione una tecla para continuar\n");
            getch();
        }else{
             aux=aux->sig;
        }
    }while(aux);
    if(!aux){
        printf("\nLos datos no han sido encontrados\nPresione una tecla para continuar\n");
        getch();
    }
}
/*void endat(struct lid **p){
char n[255],c;
struct lid *dat;
    dat=(struct lid *)malloc(sizeof(struct lid));
    if(dat){
        printf("edad:");
        fflush(stdin);
        scanf("%d",&(*dat).Edad2);
        printf("\nanio vencimiento:");
        fflush(stdin);
        scanf("%i",&(*dat).FechaVenc.Anio);
        printf("\ndia nacimiento:");
        fflush(stdin);
        scanf("%i",&(*dat).FechaNac.Dia2);
        printf("\nmes nacimiento:");
        fflush(stdin);
        scanf("%i",&(*dat).FechaNac.Mes2);
        printf("\nanio nacimiento:");
        fflush(stdin);
        scanf("%d",&(*dat).FechaNac.Anio2);
        do{
            printf("\nTRATAMIENTO : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=6);
        strcpy((*dat).Tratamiento2,n);
        do{
            printf("\nSegundo Nombre : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=2);
        strcpy((*dat).SegundoNombre2,n);
        do{
            printf("\nPrimer Nombre : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=13);
        strcpy((*dat).PrimerNombre2,n);
        do{
            printf("\nApellido : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=12);
        strcpy((*dat).Apellido2,n); fflush(stdin);
        do{
            printf("\nEmail : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=44);
        strcpy((*dat).Email2,n);
        do{
            printf("\nCiudad : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=26);
        strcpy((*dat).Ciudad2,n);
        do{
            printf("\nDepartamento : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=15);
        strcpy((*dat).Departamento2,n);
        do{
            printf("\nCodigoPostal : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=6);
        strcpy((*dat).CodigoPostal2,n);
        do{
            printf("\nOcupacion : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=81);
        strcpy((*dat).Ocupacion2,n);
        do{
            printf("\nCompania : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=36);
        strcpy((*dat).Compania2,n);
        do{
            printf("\nNumero : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=17);
        strcpy((*dat).Numero2,n);
        do{
            printf("\nTarjeta de Credito : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=11);
        strcpy((*dat).TarjetadeCredito2,n);
        do{     printf("\nCVV : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=4);
        strcpy((*dat).CVV2,n);
        do{
            printf("\nDireccion : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=24);
        strcpy((*dat).Direccion2,n);
        do{
            printf("\nTelefono : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=10);
        strcpy((*dat).NumeroTelefonico2,n);
        printf("\nPESO : ");
        fflush(stdin);
        scanf("%f",&(*dat).Peso2);
        printf("\nALTURA : ");
        fflush(stdin);
        scanf("%f",&(*dat).Altura2);
        do{
            printf("\nTipo de sangre : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=4);
        strcpy((*dat).TipodeSangre2,n);
        do{
            printf("\nFECHA VENC MES: ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=4);
        strcpy((*dat).FechaVenc.Mes,n);
        do{
            printf("\n\nSexo : ");
            fflush(stdin);
            gets(n);
        }while(strlen(n)>=10);
        strcpy((*dat).Sexo2,n);
        return;
    }
}*/
void ingresa_bin(struct binario *auxi,struct lid **p){
struct lid *act,*aux,*ant;
char b[12], b2[12],k;
int ret;
    aux=(struct lid *)malloc(sizeof(struct lid));
    if(aux){
            strcpy((*aux).Apellido2,(*auxi).Apellido);
            strcpy((*aux).PrimerNombre2,(*auxi).PrimerNombre);
            strcpy((*aux).SegundoNombre2,(*auxi).SegundoNombre);
            strcpy((*aux).Tratamiento2,(*auxi).Tratamiento);
            strcpy((*aux).Email2,(*auxi).Email);
            strcpy((*aux).Ciudad2,(*auxi).Ciudad);
            strcpy((*aux).Departamento2,(*auxi).Departamento);
            strcpy((*aux).CodigoPostal2,(*auxi).CodigoPostal);
            strcpy((*aux).Ocupacion2,(*auxi).Ocupacion);
            strcpy((*aux).Compania2,(*auxi).Compania);
            strcpy((*aux).Numero2,(*auxi).Numero);
            strcpy((*aux).TarjetadeCredito2,(*auxi).TarjetadeCredito);
            strcpy((*aux).CVV2,(*auxi).CVV);
            strcpy((*aux).Direccion2,(*auxi).Direccion);
            strcpy((*aux).NumeroTelefonico2,(*auxi).NumeroTelefonico);
            strcpy((*aux).Edad2,(*auxi).Edad);
            strcpy((*aux).Sexo2,(*auxi).Sexo);
            strcpy((*aux).TipodeSangre2,(*auxi).TipodeSangre);
            (*aux).Altura2=(*auxi).Altura;
            (*aux).Peso2=(*auxi).Peso;
            strcpy((*aux).FechaVenc.Mes,(*auxi).FechaVenc_b.Mes_b);
            strcpy((*aux).FechaVenc.Anio,(*auxi).FechaVenc_b.Anio_b);
            strcpy((*aux).FechaNac.Dia2,(*auxi).FechaNac_b.Dia2_b);
            strcpy((*aux).FechaNac.Mes2,(*auxi).FechaNac_b.Mes2_b);
            aux->FechaNac.Anio2=auxi->FechaNac_b.Anio2_b;
            if(!*p){//paso 0
                *p=aux;
                aux->sig=NULL;
                aux->ant=NULL;
                return;
            }else{
                ant=*p;
                act=*p;
                ret=strcmp(b,b2);
                while((ret<0)&&act){//paso 2      intermedio/ultimo
                    ant=act;
                    act=act->sig;
                }
                if(!act){//insertar ultimo
                    ant->sig=aux;
                    aux->sig=NULL;
                    aux->ant=ant;
                }else if(ant==act){//insertar anterior
                    *p=aux;
                    aux->sig=ant;
                    aux->ant=NULL;
                    ant->ant=aux;
                }else{//insertar intermedio
                    ant->sig=aux;
                    aux->sig=act;
                    aux->ant=ant;
                    act->ant=aux;
                }
            }
    }else{
        printf("\n\nNo hay memoria disponible\nPresione una tecla para continuar\n");
        getch();
    } return;
}
void impdat(struct lid *aux){
		printf("\nAPELLIDO : %s\n",aux->Apellido2);
        printf("\nPRIMER NOMBRE: %s\n",aux->PrimerNombre2);
        printf("\nTRATAMIENTO : %s\n",aux->Tratamiento2);
		printf("\nSEGUNDO NOMBRE : %s\n",aux->SegundoNombre2);
		printf("\nNUMERO TELEFONICO : %s\n",aux->NumeroTelefonico2);
		printf("\nEMAIL : %s\n",aux->Email2);
		printf("\nDIRECCION : %s\n",aux->Direccion2);
        printf("\nCIUDAD : %s\n",aux->Ciudad2);
		printf("\nDEPARTAMENTO : %s\n",aux->Departamento2);
		printf("\nCODIGO POSTAL : %s\n",aux->CodigoPostal2);
		printf("\nOCUPACION : %s\n",aux->Ocupacion2);
		printf("\nCOMPANIA : %s\n",aux->Compania2);
		printf("\nTARJETA DE CREDITO : %s\n",aux->TarjetadeCredito2);
		printf("\nNUMERO : %s\n",aux->Numero2);
		printf("\nCVV : %s\n",aux->CVV2);
		printf("\nFECHAVENC : {%s - %d}\n",aux->FechaVenc.Mes,*aux->FechaVenc.Anio);
        printf("\nFECHANAC : {%i-%d-%d}\n",*aux->FechaNac.Dia2,*aux->FechaNac.Mes2,aux->FechaNac.Anio2);
		printf("\nEDAD : %d\n",*aux->Edad2);
		printf("\nSEXO : %s\n",aux->Sexo2);
		printf("\nTIPO DE SANGRE : %s\n",aux->TipodeSangre2);
		printf("\nPESO : %f\n",aux->Peso2);
		printf("\nALTURA : %f\n",aux->Altura2);
}
void borra(struct lid **p){
struct lid *aux,*ant;
char b[10],b2[10],k;
int ret;

        fflush(stdin);
        printf("\nIngrese el NUMERO DE TELEFONO DE REGISTRO a borrar : ");
        gets(b);
        aux=*p;
        ant=*p;

            strcpy(b2,aux->NumeroTelefonico2);
            fflush(stdin);
            ret = strcmp(b,b2);
            if(ret==0){
                ant=aux;
                printf("%s",aux);
                printf("\nLos datos son : \n\n");
                impdat(aux);
                printf("\n\nDesea eliminar estos datos (S / N) ");
                k=getche();
                k=toupper(k);
                if(k=='S'){
                    if(ant==aux){
                        *p=aux->sig;
                        aux->sig->ant=NULL;
                    }else{
                        ant->sig=aux->sig;
                        ant->sig->ant=ant;
                    }
                    free(aux);
                    printf("Los datos han sido eliminados CORRECTAMENTE\n");
                }
            }else{
                ant=aux;
                aux=aux->sig;
            }

            if(!aux){
                printf("\nLos datos no han sido encontrados, Presione una tecla para continuar\n");
                getch();
            }

}


#include<stdlib.h>
#include<stdio.h>
#include <string.h>

int main(int argc, char * argv[]){
    FILE *fp;
    char* aux= (char *) malloc(100*sizeof(char));
    if (argc>=5){
        strcpy(aux,"/usr/share/applications/");
        
        strcat(aux,argv[1]);
        printf("%s\n",argv[1]);
        strcat(aux,".desktop");
        printf("relaunch: -Creado archivo %s\n",aux);
        fp=fopen(aux,"w");
        if (fp==NULL){
            printf("relaunch: -ERROR- fileopen==NULL\n");
            printf("relaunch: Quizás debas usar sudo para esta acción\n");
            return(1);
        }
        fprintf(fp, "[Desktop Entry]\n" );

        fprintf(fp, "Name=" );
        fprintf(fp, "%s",argv[1] );
        fprintf(fp,"\n");

        fprintf(fp, "Comment=" );
        fprintf(fp, "%s",argv[2] );
        fprintf(fp,"\n");
       
        fprintf(fp, "Exec=" );
        fprintf(fp, "%s",argv[3] );
        fprintf(fp,"\n");

        fprintf(fp, "Icon=" );
        fprintf(fp, "%s",argv[4] );
        fprintf(fp,"\n");
        if (argv[5]!=NULL){
            if(!strcmp(argv[5],"-t")){
              fprintf(fp, "Terminal=True\n" );
            }else{
              fprintf(fp, "Terminal=False\n" );
            } 
        }else{
            fprintf(fp, "Terminal=False\n" );
        } 

        fprintf(fp, "Type=Application\n" );
   	free(aux);
	 }
    else{
	printf("relaunch: -argumentos\n relaunch <nombre> <comentario> <direccion_del_programa> <direccion_del_icono> [-t (en caso de querer terminal)]\n");
	}

return 0;
}

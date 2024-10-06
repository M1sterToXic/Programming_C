#include <stdio.h>
#define H 10
#define V 5
int main(void){
	int i,j;
	for(i = 0; i < H;i++){
		for( j = 0; j < V; j++){
			switch(i){
				case 0:
					printf("%c", '*');
					break;
				case H-1:
					printf("%c", '*');
					break;
}
			if (i>0 && i<H-1)
			switch(j){
				case 0:
						printf("%c", '*');
						break;
				case V-1:
						printf("%c", '*');
						break;
				default:
						printf(" ");
						break;
}

}

			printf("\n");
}

		return 0;
}



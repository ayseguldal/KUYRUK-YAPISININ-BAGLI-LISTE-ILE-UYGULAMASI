#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;   //KUYRUKTAK� ELEMANIN VER�S�N� TUTAR.
	struct node * next;  //KUYRUKTAK� ELEMANIN G�STER�C�S�N� TUTAR.
};
  //KUYRUK YAPISI
struct node *temp=NULL;    //ELEMANI TUTACAK GE���� B�R DE���KEN OLU�TURULUR.
struct node *head=NULL;    //KUYRU�UN BA�INDAK� ELEMANI TUTAR.
struct node *tail=NULL;    //KUYRU�UN SONUNDAK� ELEMANI TUTAR.



void ElemanEkle(int sayi)
{
	struct node *eleman=(struct node*)malloc(sizeof(struct node));
	eleman->data=sayi;
	
	if(head==NULL){        //E�ER BA�TAK� ELEMAN NULL �SE YAN� KUYRUKTA ELEMAN YOKSA:
		head=eleman;  
		head->next=head;
		tail=eleman;
		tail->next=NULL;
	}
	
	else if(head->next==head){      //E�ER KUYRUKTA TEK ELEMAN VARSA:
	    tail->next=eleman;
	    tail=eleman;
	    tail->next=NULL;
	    head->next=tail;
		
	}
	
	else{           //E�ER KUYRUKTA B�RDEN FAZLA ELEMAN VARSA:
		tail->next=eleman;
		tail=eleman;
		tail->next=NULL;
	}
	
}

void ElemanSil()
{
	if(head==NULL)       //E�ER BA�TAK� ELEMAN NULL �SE YAN� KUYRUKTA ELEMAN YOKSA:
		printf("KUYRUK BOS...");
		
	else{    //E�ER KUYRUKTA B�R VE B�RDEN FAZLA ELEMAN VARSA:
	    printf("%d elmani kuyruktan cikartildi ",head->data);
		temp=head->next;
	    free(head);
	    head=temp;	
	}
	
}

void yazdir()      //EKRANA YAZDIRMA FONKS�YONU 
{
	system("cls");    //HER YAZDIRMADAN �NCE EKRANI TEM�ZLER.
	if(head==NULL)
	   printf("KUYRUK BOS...");
	   
	else{
		temp=head;
		while(temp->next!=NULL){    //SON ELEMANA GELENE KADAR YAZDIRIR.
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);  //SON ELEMANI YAZDIRIR.
	}

   printf("\n");
}


int main() {
	int secim,sayi;
	while(1){   //�IKANA KADAR SE��MLER EKRANA YAZDIRILIR
		printf("\nLutfen asagidaki islemlerden birini seciniz \n");
		printf("1.Ekleme\n");
		printf("2.SIlme\n");
		printf("3.Goruntuleme\n");
		printf("4.CIKIS\n");
		printf("SECIMINIZ:");
		scanf("%d",&secim);    //YAPACA�I ��LEM KULLANICIDAN ALINIR
		
		switch(secim){
			case 1:    // 1 G�R�L�RSE EKLEME ��LEM� YAPILIR
			printf("Eklenicek sayiyi giriniz:");
			scanf("%d",&sayi);  //EKLEN�LCEK SAYI KULLANICIDAN ALINIR
			ElemanEkle(sayi);   //EKLEME FONKS�YONUNA ELEMAN G�NDER�L�R
			break;
			
			case 2:   // 2 G�R�L�RSE S�LME ��LEM� YAPILIR
			ElemanSil();  //S�LME FONKS�OYONU �A�IRILIR
			break;
			
			case 3:  // 3 G�R�L�RSE ELEMANLAR EKRANA YAZDIRILIR
			yazdir();   //YAZDIRMA FONKS�YONU �A�IRILIR
			break;
			
			case 4:  // 4 G�R�L�RSE �IKI� YAPILIR
				return 0;  
			
			default:  // 1,2,3,4 DI�INDA B�R KARAKTER G�R�L�RSE HATA VER�R 
			printf("ISTENEN SECIMLERDEN BIRINI GIRMEDINIZ!!\n");
		
		}
	}
}

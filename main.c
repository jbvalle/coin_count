/*
Author: John Bryan Valle
Project: Coin Counter
*/

#include <stdio.h>
#include <stdlib.h>

int countcoins(int cent_amount, int *cent_coins, int *coin_values);

int main(void) {

  int cent_amount, coin_values[4] = {10,5,2,1};
  int *cent_coins = (int*)malloc(4*sizeof(int));
  for(int i = 0; i < 4; i++)*(cent_coins + i) = 0;


  //Eingabe anfordern
  printf("Cent Betrag eingeben: ");
  scanf("%d",&cent_amount);getchar();

  (void) countcoins(cent_amount, cent_coins, coin_values);

  printf("%dx10ct %dx5ct %dx2ct %dx1ct\n",cent_coins[0], cent_coins[1], cent_coins[2], cent_coins[3]);

  return 0;
}

int countcoins(int cent_amount, int *cent_coins, int *coin_values){

  for (int j = 0; (j < 4)&&(cent_amount > 0);) {
    if((cent_amount - coin_values[j]) >= 0){
      cent_amount -= coin_values[j];
      *(cent_coins + j) += 1;
    }else j++;
  }
  return 0;
}

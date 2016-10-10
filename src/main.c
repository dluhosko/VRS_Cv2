/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 6.0.0   2016-10-09

The MIT License (MIT)
Copyright (c) 2009-2016 Atollic AB

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************
*/

/* Includes */
#include <stddef.h>
#include "stm32l1xx.h"


/* Private typedef */
/* Private define  */
/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */


/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  int i = 0;
  uint32_t BUTTON=0;
  uint8_t BUTTON_akt=0;
  uint8_t BUTTON_min=0;
  uint8_t stlacene=0;
  int pocitadlo=0;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

  /*uloha 1
   GPIOA->MODER = GPIOA->MODER  | (0xb1<<10);
  GPIOA->MODER = GPIOA->MODER  &  ~(uint32_t)(0xb1<<11);

  GPIOA->OTYPER = GPIOA->MODER & ~(uint32_t)(0xb1<<5);

  GPIOA->PUPDR = GPIOA->PUPDR  | (0xb1<<10);
  GPIOA->PUPDR = GPIOA->PUPDR  & ~(uint32_t)(0xb1<<11);

  GPIOA->OSPEEDR = GPIOA->OSPEEDR | (0xb11<<10);
  */
  //uloha2
/*
  GPIOC->MODER = GPIOC->MODER & ~(uint32_t)(0xb11<<26);
  GPIOC->OTYPER = GPIOC->OTYPER & ~(uint32_t)(0xb1<<13);
  GPIOC->PUPDR = GPIOC->PUPDR & ~(uint32_t)(0xb11<<26);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
*/
  //uloha 3
  //nastavenie vystupu pre LED

   GPIOA->MODER = GPIOA->MODER  | (0xb1<<10);
   GPIOA->MODER = GPIOA->MODER  &  ~(uint32_t)(0xb1<<11);
   GPIOA->OTYPER = GPIOA->MODER & ~(uint32_t)(0xb1<<5);
   GPIOA->PUPDR = GPIOA->PUPDR  | (0xb1<<10);
   GPIOA->PUPDR = GPIOA->PUPDR  & ~(uint32_t)(0xb1<<11);
   GPIOA->OSPEEDR = GPIOA->OSPEEDR | (0xb11<<10);
   //Nastavenie tlacidla
   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
   GPIOC->MODER = GPIOC->MODER & ~(uint32_t)(0xb11<<26);
   GPIOC->OTYPER = GPIOC->OTYPER & ~(uint32_t)(0xb1<<13);
   GPIOC->PUPDR = GPIOC->PUPDR & ~(uint32_t)(0xb11<<26);

  /* TODO - Add your application code here */


  /* Infinite loop */
  while (1)
  {
	  //uloha 1a
	/*  GPIOA->ODR = GPIOA->ODR | (0xb1<<5);
	for (i=0;i<500000;i++);
	GPIOA->ODR = GPIOA->ODR & ~(uint32_t)(0xb1<<5);
	for (i=0;i<500000;i++);

	 */
	  //uloha 1b
	  /*
	   GPIOA->BSRRH = GPIOA->BSRRH | (0xb1<<5);
	   	for (i=0;i<500000;i++);
		GPIOA->BSRRL = GPIOA->BSRRL | (0xb1<<5);
		for (i=0;i<500000;i++);
		*/
	  //uloha 1c
	  /*
	  GPIOA->ODR = GPIOA->ODR ^ (0xb1<<5);
	  for (i=0;i<500000;i++);
	  */

	  //Uloha 2
	  /*
	  BUTTON = !(GPIOC->IDR & (0xb1<<13));
	*/

	  //Uloha3
	  //cast a
	  /*GPIOA->ODR = GPIOA->ODR | (0xb1<<5);
	  	for (i=0;i<500000;i++);
	  	GPIOA->ODR = GPIOA->ODR & ~(uint32_t)(0xb1<<5);
	  	for (i=0;i<500000;i++);
		*/
	  //cast b
/*
	  BUTTON = (GPIOC->IDR & (0xb1<<13));
	  if (BUTTON == 0)
	  {
		  GPIOA->ODR = GPIOA->ODR | (0xb1<<5);
	  }
	  else
	  {
		  GPIOA->ODR = GPIOA->ODR & ~(uint32_t)(0xb1<<5);
	  }
*/
	  //cast c
	 BUTTON = !(GPIOC->IDR & (0xb1<<13));
	 if (BUTTON ^ stlacene)
	 {
		 stlacene = BUTTON;
		 pocitadlo = 0;
	 }
	 else
	 {
		 if ((pocitadlo <=100) && (stlacene ==1))
		 {
		 pocitadlo ++;
		 }
	 }
	 if (pocitadlo == 100)
	 {
		 GPIOA->ODR = GPIOA->ODR ^ (0xb1<<5);
	 }

  }


  return 0;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}

/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}

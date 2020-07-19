#ifdef MAIN_H_
#define MAIN_H_

typedef struct
{
    
    uint32_t gpioa_en:1;
    uint32_t gpiob_en:1;
    uint32_t gpioc_en:1;
    uint32_t gpiod_en:1;
    uint32_t gpioe_en:1;
    uint32_t gpiof_en:1;
    uint32_t gpiog_en:1;
    uint32_t gpioh_en:1;
    uint32_t gpioi_en:1;
    uint32_t reserved:3;
    
}RCC_AHB1ENR_t;

#endif // MAIN_H_
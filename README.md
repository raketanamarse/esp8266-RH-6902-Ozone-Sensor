# esp8266-RH-6902-Ozone-Sensor

esp8266 (lolin wemos d1 mini) ----> rs485 (Модуль MAX485) ----> RH-6902 ( Digital Ozone Sensor ) https://aliexpress.ru/item/4001248121949.html?item_id=4001248121949&sku_id=10000015456763122&spm=a2g2w.productlist.0.0.122d9f00eRid3q

В проекте используеться датчик растворенного озона RH-6902
через интерфейс rs485 (используеться конвертер) https://aliexpress.ru/item/32848344535.html?sku_id=65155011742&spm=a2g0o.search.0.0.3f4b15cdODkTN7

    wemos d1 mini |  D7 --- RO | Модуль MAX485 
                  |  D6 --- RE | 
                  |     \__ DE | 
                  |  D8 --- DI | 

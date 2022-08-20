# esp8266-RH-6902-Ozone-Sensor

esp8266 (lolin wemos d1 mini) ----> rs485 (Модуль MAX485) ----> RH-6902 ( Digital Ozone Sensor ) https://aliexpress.ru/item/4001248121949.html?item_id=4001248121949&sku_id=10000015456763122&spm=a2g2w.productlist.0.0.122d9f00eRid3q

В проекте используется датчик растворенного озона RH-6902
через интерфейс rs485 (используется конвертер) https://aliexpress.ru/item/32848344535.html?sku_id=65155011742&spm=a2g0o.search.0.0.3f4b15cdODkTN7

    wemos d1 mini |  D7 --- RO | Модуль MAX485 
                  |  D6 --- RE | 
                  |     \__ DE | 
                  |  D8 --- DI | 


НИКОГДА не спользуете gpio2, gpio0, gpio15 для эмуляции  SoftwareSerial --> так как напряжение на этих пинах отвечает за тип заерузки платы 
![изображение](https://user-images.githubusercontent.com/104571006/185757983-ad783d9d-1677-49b4-88fd-dfd6af976ee0.png)

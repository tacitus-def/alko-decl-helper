# alko-decl-helper
Приложение для формирования алкогольных деклараций по формам №11 и №12

Формирование алкогольных деклараций по формам №11 и №12 из файла в формате CSV для Федеральной службы по регулированию алкогольного рынка РФ.

Возможности:
* Импорт данных из CSV-файла.
* Импорт остатков на начало периода из CSV-файла.
* Редактирование данных в таблице.
* Для удобства редактирования в таблице с данными реализован простой калькулятор.
* Сохранение и загрузка данных.
* Формирование деклараций по формам №11 и №12 в формате Декларант-Алко 4.31.

Для облегчения процесса импорта данных из CSV-файла в первой строке после октоторпа (знак «#») можно указать типы колонок таблицы:

1.  Сокрытие колонки — `HIDE`
2.  Код (тип) продукта — `PRODUCT_TYPE`
3.  Наименование производителя — `PRODUCER_NAME`
4.  ИНН производителя — `PRODUCER_INN`
5.  КПП производителя — `PRODUCER_KPP`
6.  Наименование поставщика/импортёра — `SUPPLIER_NAME`
7.  ИНН поставщика/импортёра — `SUPPLIER_INN`
8.  КПП поставщика/импортёра — `SUPPLIER_KPP`
9.  Номер и серия лицензии — `LICENSE_NUMBER`
10. Дата выдачи лицензии — `LICENSE_SDATE`
11. Дата окончания лицензии — `LICENSE_EDATE`
12. Лицензиар — `LICENSE_DEPARTMENT`
13. Дата ТТН — `TTN_DATE`
14. Номер ТТН — `TTN_NUMBER`
15. Номер таможенной декларации — `TD_NUMBER`
16. Декалитры (ДАЛ) — `NUMBER_DKL`

Похожим образом производится импорт остатков на начало периода со следующими колонками в таблице:

1.  Сокрытие колонки — `HIDE`
2.  Код (тип) продукта — `PRODUCT_TYPE`
3.  Наименование производителя — `PRODUCER_NAME`
4.  ИНН производителя — `PRODUCER_INN`
5.  КПП производителя — `PRODUCER_KPP`
6.  Декалитры (ДАЛ) — `NUMBER_DKL`

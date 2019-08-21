# grocerylist
Description
Write an application in C++ for a mini market to keep track of its inventories. Create at least 20 records (with item number, item name, size, brand, price, quantity, supplier and contact – you may add more) in a text file. The application should read the item records from the text file and insert them into an array of structures.

After the records are stored to the array, display a menu with the following options:
(a)	List – Display the list of all records. The display should contain an appropriate heading and column captions;
(b)	Search by item number – Search and display the record which matches the item number. You have to tell no records found if none of them matches the searched item number;
(c)	Search by keyword – Search the records using a keyword and print out all the records which match the searched keyword. You have to tell no records found if none of them matches the keyword; (Refer to example below) 
(d)	Show low inventories – Search and display the records with quantity less than 10 units so that the items can be replenished; (Refer to example below)
(e)	Update – Ask user for an item number. If any record matches the item number, user will be asked to key in the new data for item name, size, brand, price, quantity, supplier and contact. Then the record will be updated accordingly;
(f)	Add – Add a new record to the list;
(g)	Delete – Delete a record from the list;
(h)	Exit – Stop the program. Once the exit option is chosen, the application will update the text file accordingly with all the changes which have been done.

Sample text file

Item Number	Item Name	Size	Brand		Price	Qty	Supplier			Contact	      
12300		cooking oil	5kg	Knife		19.99	20	Ahmad Zalini		012-3140622
12301		cooking oil	5kg	Red Eagle	22.45	  9	Mohammad Ridzuan	011-1234567
12302		white rice super	10kg	Jati		24.99	18	Mohammad Ridzuan	011-1234567
12303		white rice super	10kg	Jasmine		26.99	  8	Albert Loo		017-6481238
12304		chilli sauce	500g	Life		  3.19      10	Eric Chua		019-2123333
12305		chilli sauce	500g	Kimball		  3.30	15	Lee King Chong		012-3716215
12306		chilli sauce	500g	Maggi		  3.00	11	Lee King Chong		012-3716215
…

Example for Part (c)
If search by keyword “li”, the application will display the following result:

Item Number	Item Name	Size	Brand		Price	Qty	Supplier			Contact	      
12300		cooking oil	5kg	Knife		19.99	20	Ahmad Zalini		012-3140622
12304		chilli sauce	500g	Life		  3.19      10	Eric Chua		019-2123333
12305		chilli sauce	500g	Kimball		  3.30	15	Lee King Chong		012-3716215
12306		chilli sauce	500g	Maggi		  3.00	11	Lee King Chong		012-3716215
…

Example for Part (d)
Items with low inventories:

Item Number	Item Name	Size	Brand		Price	Qty	Supplier			Contact	      
12301		cooking oil	5kg	Red Eagle	22.45	  9	Mohammad Ridzuan	011-1234567
12303		white rice super	10kg	Jasmine		26.99	  8	Albert Loo		017-6481238
…

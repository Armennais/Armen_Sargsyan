-- create database armen;
-- use armen;
CREATE TABLE Author (
	ID INT NOT NULL AUTO_INCREMENT,
	`Name` VARCHAR(30),
	CONSTRAINT PK_Author PRIMARY KEY(ID)
);
CREATE TABLE Publisher(
	ID INT NOT NULL AUTO_INCREMENT,
	`Name` VARCHAR(30),
	CONSTRAINT PK_Publisher PRIMARY KEY(ID)
);
CREATE TABLE Book (
	ID INT NOT NULL AUTO_INCREMENT,
	Title VARCHAR(30),
	Pub_data DATE,
	Author_ID INT,
	Publisher_ID INT,
	CONSTRAINT PK_Book PRIMARY KEY(ID),
	CONSTRAINT FK_Book_Author FOREIGN KEY(Author_ID) REFERENCES Author(ID),
    CONSTRAINT FK_Book_Publisher FOREIGN KEY(Publisher_ID) REFERENCES Publisher(ID)
);
CREATE TABLE Subscriber(
	ID INT NOT NULL AUTO_INCREMENT,
	`Name` VARCHAR(30),
    `Surname` VARCHAR(30),
    B_day DATE,
    Address VARCHAR(30),
	CONSTRAINT PK_Subsciber PRIMARY KEY(ID)
);
CREATE TABLE Subscriber_book(
	ID INT NOT NULL AUTO_INCREMENT,
    Subscriber_ID INT,
    Taken_date DATE,
    Returned_date DATE,
    Deadline DATE,
    CONSTRAINT PK_Subscriber_book PRIMARY KEY(ID),
    CONSTRAINT FK_Subscriber_book_Subscriber FOREIGN KEY(Subscriber_ID) REFERENCES Subscriber(ID)
);
CREATE TABLE Book_inventory(
	ID INT NOT NULL AUTO_INCREMENT,
    Book_ID INT,
    Sub_Book_ID INT,
    `Condition` VARCHAR(30),
    `Status` VARCHAR(30),
    CONSTRAINT PK_Book_inventory PRIMARY KEY(ID),
    CONSTRAINT FK_Book_inventory_Book FOREIGN KEY (Book_ID) REFERENCES Book(ID),
    CONSTRAINT FK_Book_inventory_Subscriber_book FOREIGN KEY (Sub_Book_ID) REFERENCES Subscriber_book(ID)
);
INSERT INTO Author(`Name`)
VALUES ('Sero Ghanzadyan'),
	('Theodore Dreiser'),
    ('Paulo Coelho'),
    ('Alexandre Dumas');
INSERT INTO Publisher(`Name`)
VALUES ('Antares'),
	('Edit Print'),
    ('Dizak');
INSERT INTO Book (Title,Pub_data,Author_ID,Publisher_ID)
VALUES (N'Անձրևից հետո','1966-05-12',1,1), 
    (N'Քաջարան','1965-05-21',1,3),
    ('Sister Carrie','1985-07-01',2,3),
    ('The Financier','1912-07-08',2,3),
    ('The Alchemist','1988-04-12',3,2),
    ('Brida','1990-02-10',3,1),
    ('The Three Musketeers','1844-05-09',4,2),
    ('The Count of Monte Cristo','1845-12-17',4,3);

INSERT INTO Subscriber (`Name`,`Surname`,B_day,Address)
VALUES
    ('Armen','Sargsyan','1999-12-03','Martakert'),
    ('Robert','Qocharyan','1954-08-31',"Stepanakert"),
    ('Levon','Ter-Petrosyan','1945-01-09','Aleppo'),
    ('Serzh','Sargsyan','1954-06-30','Stepanakert'),
    ('Nikol','Pashinyan','1975-06-01','Ijevan');


INSERT INTO Subscriber_book(Subscriber_ID,Taken_date,Returned_date,Deadline)
VALUES (1,'2022-02-06',NULL,'2022-03-06'),
	(2,'2022-01-06','2022-02-01','2022-02-06'),
    (3,'2022-02-04',NULL,'2022-03-07');
    
INSERT INTO Book_inventory (Book_ID,Sub_Book_ID,`Condition`,`Status`)
VALUES
    (1,2,'Old','Renoveted'),
	(2,3,'New','Free'),
    (3,1,'Old','Busy');
    
alter table book_inventory
 drop foreign key FK_Book_inventory_Subscriber_book;

ALTER TABLE book_inventory
DROP COLUMN Sub_book_ID;

ALTER TABLE subscriber_book
  ADD Book_inventory varchar(30) NOT NULL
    AFTER Subscriber_ID;

alter table subscriber_book
	add constraint fk_subscriber_book foreign key (Subscriber_ID) REFERENCES book_inventory(ID);
    
create table `User`(
	ID int not null auto_increment,
    `Name` varchar(30),
    `Surename` varchar(30),
    constraint PK_user_id primary key (ID)
);

alter table subscriber_book
drop column user_id;
ALTER TABLE subscriber_book
  ADD column user_id int;
insert into `user`(`Name`,`Surename`) 
values ('Armen','Grigoryan'),
	('Vazgen','Arustamyan');
select * from `user`;
  
  
alter table subscriber_book
add constraint fk_subscriber_book_user foreign key (user_id) REFERENCES `user`(ID);     

alter table subscriber_book
add column book_id int;

alter table subscriber_book
add constraint fk_subscriber_book_Book foreign key (book_id) REFERENCES book(ID);    
drop view books_of_subscribers;


CREATE VIEW books_of_subscribers AS
select subscriber.`Name`,subscriber.Surname,book.Title,Taken_date,Returned_date,Deadline
from subscriber_book
inner join subscriber 
on subscriber.ID = subscriber_book.ID
inner join book
on book.ID = subscriber_book.ID;
drop view book_in_repair;


create view book_in_repair as
select book.Title, book_inventory.`Status`
from book
inner join book_inventory 
on book.ID = book_inventory.ID
where book_inventory.`Status` = 'Renoveted';

select * from book_in_repair;

select book_in_repair.Title , count(*) as `count` from  book_in_repair 
group by book_in_repair.Title;

select Count(*) as delays from books_of_subscribers
	where (Returned_date is null
     and (CURDATE() > Deadline )) or (Returned_date is not null
     and ( Returned_date > Deadline ));

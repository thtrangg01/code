﻿CREATE DATABASE QLKH;
DROP DATABASE QLKH; /* XÓA DATABASE */

USE QLKH;

 DROP TABLE KHACHHANG;
 
CREATE TABLE KHACHHANG (
MAKH INT   NOT NULL,
TENKH NVARCHAR (20)  NOT NULL,
TUOI INT   NOT NULL,
DIACHI NCHAR (25),
LUONG  DECIMAL (18,2) ,
PRIMARY KEY (MAKH) );

INSERT INTO KHACHHANG VALUES (01 , N'Trịnh Khánh Huyền', 20 , N'Đông Anh', 2000.6);
INSERT INTO KHACHHANG VALUES (02 , N'Bùi Văn Cường', 19 , N'Bắc Giang', 350006.74);
INSERT INTO KHACHHANG VALUES (03 , N'Trần Mai Duy', 23 , N'Phú Thọ', 10640.32);
INSERT INTO KHACHHANG VALUES (04 , N'Phạm Quang Huy', 20 , N'Phú Thọ', 2063.064);
INSERT INTO KHACHHANG VALUES (05 , N'Vũ Minh Thành', 25 , N'Quảng Ninh', 2000);
INSERT INTO KHACHHANG VALUES (06 , N'Trần Thị Hiền', 20 , N'Nam Định', 2306420.36);
INSERT INTO KHACHHANG VALUES (07 , N'Bùi Như Quỳnh', 23 , N'Vĩnh Phúc', 1900.67);
INSERT INTO KHACHHANG VALUES (08 , N'Tô Ngọc Mai', 19 , N'Hà Nội', 63084.167);
INSERT INTO KHACHHANG VALUES (09 , N'Nguyễn Thị Thu Trang', 22 , N'Bắc Ninh', 22092001);
INSERT INTO KHACHHANG VALUES (10 , N'Nguyễn Thùy Giang', 34 , N'Bắc Ninh', 200000);
INSERT INTO KHACHHANG VALUES (11 , N'Nguyễn Đình Chi', 30 , N'Quế Võ', 454046);
INSERT INTO KHACHHANG VALUES (12 , N'Phạm Bảo Ngọc', 20 , N'Thái Bình', 13056);
INSERT INTO KHACHHANG VALUES (13 , N'Nguyễn Thị Hải Yến', 35 , N'Ba Vì', 135456);
INSERT INTO KHACHHANG VALUES (14 , N'Lê Minh Phương', 22 , N'Ba Đình', 187643);
INSERT INTO KHACHHANG VALUES (15 , N'Nguyễn Thị Diệu Hằng', 27 , N'Hà Tĩnh', 136046);
INSERT INTO KHACHHANG VALUES (16 , N'Ngô Thị Mai', 19 , N'Nghệ An', 1698130);
INSERT INTO KHACHHANG VALUES (17 , N'Phạm Linh Hằng', 26 , N'Hà Nội', 201300);
INSERT INTO KHACHHANG VALUES (18 , N'Nguyễn Phương Lan', 28 , N'Bắc Ninh', 23000000);
INSERT INTO KHACHHANG VALUES (19 , N'Nguyễn Hữu Hiếu', 27 , N'Thuận Thành', 30052007);
INSERT INTO KHACHHANG VALUES (20 , N'Choi Min', 24 , N'TP.Bắc Ninh', 14072018);


SELECT * FROM KHACHHANG;


UPDATE KHACHHANG SET DIACHI = 'TPHCM' WHERE MAKH = 12 ;

UPDATE KHACHHANG SET DIACHI = 'HA NOI', LUONG = 1500000;

SELECT * FROM KHACHHANG WHERE TUOI >= 30 ;

SELECT COUNT(MAKH) AS SL FROM KHACHHANG WHERE TUOI >= 30;

DELETE FROM KHACHHANG WHERE TUOI = 24;

SELECT * FROM KHACHHANG WHERE TUOI = 26 AND DIACHI = N'Hà Nội';

SELECT * FROM KHACHHANG WHERE TUOI = 26 OR TUOI = 27;

SELECT * FROM KHACHHANG WHERE TENKH LIKE N'%Thị%'; /* chọn những kh có tên gồm chữ thị */


ALTER TABLE KHACHHANG ADD GHICHU NCHAR (100);

ALTER TABLE KHACHHANG DROP COLUMN GHICHU;

ALTER TABLE KHACHHANG ALTER COLUMN GHICHU2 CHAR (50);

UPDATE KHACHHANG SET TUOI = TUOI + 3 ;
SELECT DISTINCT (DIACHI) FROM KHACHHANG ;

SELECT DIACHI, COUNT(MAKH)AS SL FROM KHACHHANG GROUP BY DIACHI HAVING COUNT(MAKH) >= 2;
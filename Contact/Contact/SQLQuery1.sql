CREATE TABLE PeoInfo
(
	Name VARCHAR (20) NOT NULL CONSTRAINT PeoInfo_Prim PRIMARY KEY,
	Sex NVARCHAR (5) NOT NULL,
	Age INT NOT NULL,
	Tele NVARCHAR (12) NOT NULL,
	Addr NVARCHAR (25) NOT NULL
)
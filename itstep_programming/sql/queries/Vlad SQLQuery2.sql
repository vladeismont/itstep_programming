---------- ������� ��� �� ----------------
GO
CREATE TABLE [People]
(
    [Id] INT identity(1,1) NOT NULL PRIMARY KEY, 
    [Firstname] NVARCHAR(MAX) NOT NULL, 
    [Lastname] NVARCHAR(MAX) NOT NULL, 
    [Birthdate] DATE NULL, 
    [PersonalNumber] CHAR(16) NULL,
    [MoodId] INT NULL,
	[numPhones] INT NOT NULL
)

GO

CREATE TABLE [dbo].[Phones]
(
    [Id] INT identity(1,1) NOT NULL PRIMARY KEY, 
    [people_id] INT NOT NULL, 
    [phone] VARCHAR(MAX) NOT NULL, 
    CONSTRAINT [FK_Phones_To_People] FOREIGN KEY (people_id) REFERENCES People([Id]) 
    ON DELETE CASCADE
)



GO

CREATE TABLE [dbo].[friendship] (
    [id1] INT NOT NULL,
    [id2] INT NOT NULL,
    CONSTRAINT [PK] PRIMARY KEY CLUSTERED ([id1] ASC, [id2] ASC)
);
GO

INSERT INTO [dbo].[friendship] ([id1], [id2]) VALUES (1, 2)
, (1, 3)
, (2, 4)
, (2, 6)
, (3, 4)
, (3, 7)
, (4, 5)
, (6, 7)
, (6, 8)
, (7, 2)
, (8, 1)

SET IDENTITY_INSERT [dbo].[People] ON
INSERT INTO [dbo].[People] ([Id], [Firstname], [Lastname], [Birthdate], [PersonalNumber], [MoodId], [numPhones]) VALUES (1, N'Lala', N'Ava', NULL, N'11              ', 1, 3)
, (2, N'Lol', N'Orava', NULL, N'12              ', 1, 1)
, (3, N'Col', N'Lama', NULL, N'13              ', 2, 0)
, (4, N'Basha', N'Rama', NULL, N'14              ', 2, 0)
, (5, N'Wnshu', N'Krshna', NULL, N'15              ', 1, 0)
, (6, N'Rinpoche', N'Patrol', NULL, N'16              ', 3, 0)
, (7, N'Krala', N'Ava', NULL, N'17              ', 1, 0)
, (8, N'Mlavaja', N'Ava', NULL, N'18              ', 2, 0)
SET IDENTITY_INSERT [dbo].[People] OFF

SET IDENTITY_INSERT [dbo].[Phones] ON
INSERT INTO [dbo].[Phones] ([Id], [people_id], [phone]) VALUES (2078, 1, N'1242')
, (2079, 1, N'45-3f')
, (2080, 2, N'2-232')
, (2081, 1, N'5446')
SET IDENTITY_INSERT [dbo].[Phones] OFF


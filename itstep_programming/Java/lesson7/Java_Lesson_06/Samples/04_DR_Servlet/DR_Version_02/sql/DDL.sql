create database DR;

create table Project
(
    ProjectID integer not null primary key AUTO_INCREMENT,
    `Name` varchar(100) not null unique
);

create table Task
(
    TaskID integer not null primary key AUTO_INCREMENT,
    ProjectID integer not null references Project(ProjectID),
    ReportedAt datetime not null,
    Hours numeric(3,1) not null,
    Description varchar(1000) not null
);
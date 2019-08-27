insert into Project (`Name`) values ('Easy Payment');
insert into Project (`Name`) values ('Virtual Market');
insert into Project (`Name`) values ('SCP');

insert into Task (ProjectID, ReportedAt, Hours, Description) values (1, '2010/10/13 10:12:12', 2, 'Bug: incorrect order total cost');
insert into Task (ProjectID, ReportedAt, Hours, Description) values (2, '2010/10/13 12:15:00', 2, 'Improvement: change layout on the main customer page');
insert into Task (ProjectID, ReportedAt, Hours, Description) values (3, '2010/10/13 17:30:17', 3, 'New Feature: implement user email notification');
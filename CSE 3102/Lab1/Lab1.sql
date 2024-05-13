--Create Table Director

-- CREATE TABLE Director (
--     Person_ID INT,
--     Director_Name VARCHAR(255),
--     Birth_Year YEAR,
--     No_Of_Films INT,
--     No_Of_Awards INT
-- );

-- INSERT INTO Director 

-- INSERT INTO Director (Person_ID, Director_Name, Birth_Year, No_Of_Films, No_Of_Awards)
-- VALUES
--     (1, 'Zahir Raihan', 1935, 5, 5),
--     (2, 'Rajkumar Hirani', 1962, 5, 9),
--     (3, 'Satyajit Ray', 1921, 45, 55),
--     (4, 'Anjan Dutt', 1953, 23, 17),
--     (5, 'Rituparno Ghosh', 1963, 20, 15),
--     (6, 'Goutam Ghose', 1950, 12, 8),
--     (7, 'Aparna Sen', 1945, 12, 7),
--     (8, 'Kaushik Ganguly', 1968, 23, 30)

--Create Table Actor

-- CREATE TABLE Actor (
--     Person_ID INT,
--     Director_Name VARCHAR(255),
--     Birth_Year YEAR,
--     No_Of_Films INT,
--     No_Of_Awards INT,
--     PRIMARY KEY (Person_ID)
-- );

--Insert into Actor

-- INSERT INTO Actor (Person_ID, Actor_Name, Birth_Year, No_Of_Films, No_Of_Awards)
-- VALUES
--     (11, 'Uttam Kumar', 1926, 190, 150),
--     (12, 'Razzak', 1942, 120, 100),
--     (7, 'Aparna Sen', 1945, 73, 43),
--     (6, 'Goutam Ghose', 1950, 3, 1),
--     (8, 'Kaushik Ganguly', 1968, 22, 7),
--     (10, 'Soumitra Chatterjee', 1935, 250, 220),
--     (4, 'Anjan Dutt', 1953, 39, 10)

--Create Table Movie

-- CREATE TABLE Movie (
--     Movie_ID INT PRIMARY KEY,
--     Movie_Name VARCHAR(255),
--     Genre VARCHAR(255),
--     Year INT,
--     IMDB_Rating DECIMAL(3,1),
--     Director_ID INT,
--     FOREIGN KEY (Director_ID) REFERENCES Director(Person_ID)
-- );

--Insert into Movie

-- INSERT INTO Movie (Movie_ID, Movie_Name, Genre, Year, IMDB_Rating, Director_ID)
-- VALUES
--     (1, 'Pather Panchali', 'Drama', 1955, 8.5, 3),
--     (2, 'Noukadubi', 'Drama', 2011, 7.6, 5),
--     (3, 'Abohomaan', 'Drama', 2009, 7.3, 5),
--     (4, 'Joi Baba Felunath', 'Thriller', 1979, 8.0, 3),
--     (5, 'Jibon Theke Neya', 'Drama', 1970, 9.4, 1),
--     (6, 'Moner Manush', 'Biography', 2010, 8.0, 6),
--     (7, 'Apur Panchali', 'Biography', 2013, 8.2, 8),
--     (8, 'Goynar Baksho', 'Comedy', 2013, 7.1, 7),
--     (9, 'Byomkesh O Agnibaan', 'Thriller', 2017, 7.4, 4),
--     (10, 'Byomkesh Bakshi', 'Thriller', 2010, 7.4, 4),
--     (11, 'PK', 'Fiction', 2014, 8.2, 2);

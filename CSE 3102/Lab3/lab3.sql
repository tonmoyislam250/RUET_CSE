-- Level 1:
-- 1.
SELECT Movie_Name, IMDB_Rating
FROM movie
ORDER BY IMDB_Rating DESC, Movie_Name ASC;

-- 2.
SELECT COUNT(*) AS TOTAL_MOVIES
FROM movie;

-- 3.
SELECT COUNT(DISTINCT Genre) AS TOTAL_GENRES
FROM movie;

-- 4.
SELECT AVG(IMDB_Rating) AS Average_Rating
FROM movie
WHERE Genre="Drama";

-- 5.
SELECT Genre,COUNT(Director_ID) AS TOTAL_MOVIES
FROM movie
GROUP BY Genre;




-- Level 2:
-- 1.
SELECT AVG(No_Of_Films) AS Avg_NO_OF_DIR_MOV
FROM director;

-- 2.
SELECT Movie_Name, Genre, IMDB_Rating, Director_Name
FROM movie JOIN director ON Director_ID=Person_ID
WHERE Director_Name IN ("Satyajit Ray","Zahir Raihan", "Rituparno Ghosh", "Kaushik Ganguly");

-- 3.
SELECT Actor_Name AS Name, (YEAR(CURRENT_DATE) - Birth_Year) AS Current_Age FROM Actor
UNION SELECT Director_Name AS Name, (YEAR(CURRENT_DATE) - Birth_Year) AS Current_Age FROM Director;

-- 4.
SELECT A.Actor_Name, (YEAR(CURRENT_DATE) - A.Birth_Year) AS Current_Age, A.No_Of_Films AS AFlims , D.No_Of_Films AS DFlims
FROM Actor A JOIN Director D ON A.Person_ID = D.Person_ID WHERE D.No_Of_Films > 0;

-- 5.
SELECT D.Director_Name, COUNT(M.Movie_ID) AS No_Of_Movies_Directed 
FROM director D LEFT JOIN movie M ON D.Person_ID = M.Director_ID 
GROUP BY D.Director_Name;

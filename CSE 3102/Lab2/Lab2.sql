-- Query 1.1: Find the name, genre, and IMDB rating of all the movies.
SELECT Movie_Name, Genre, IMDB_Rating FROM movie;
-- ❖ Query 1.2: Display all the distinct movie-genres.
SELECT DISTINCT Genre FROM movie;
-- ❖ Query 1.3: Find the name and current age of all the actors.
SELECT Actor_Name, (YEAR(CURRENT_DATE) - Birth_Year) AS Current_Age FROM Actor;
-- ❖ Query 1.4: Find all the movies of the thriller genre with an IMDB rating greater than or equal to 8.0.
SELECT Movie_Name, Genre, IMDB_Rating FROM Movie WHERE Genre = 'Thriller' AND IMDB_Rating >= 8.0;
-- ❖ Query 1.5: Find the name, release year, IMDB rating, and the name of the director of all the movies.
SELECT m.Movie_Name, m.Year AS Release_Year, m.IMDB_Rating, d.Director_Name AS Director_Name FROM Movie m JOIN Director d ON m.Director_ID = d.Person_ID;
-- ❖ Query 1.6: Find the name and number of awards of those directors whose name starts with a ‘S’ or a ‘A’.
SELECT Director_Name, No_Of_Awards FROM Director WHERE Director_Name LIKE 'S%' OR Director_Name LIKE 'A%';
-- ❖ Query 1.7: Find the name and birth year of those directors whose name contains an ‘a’ as its 2nd last character.
SELECT Director_Name, Birth_Year FROM Director WHERE Director_Name LIKE '%a_';
-- ❖ Query 1.8: Find the name, release year, and genre of all the movies which contain the word ‘Byomkesh’ anywhere in their name.
SELECT Movie_Name, Year AS Release_Year, Genre FROM Movie WHERE Movie_Name LIKE '%Byomkesh%';
-- ❖ Query 1.9: Find the name and IMDB rating of all the movies whose name consists of only 2 characters.
SELECT Movie_Name, IMDB_Rating FROM Movie WHERE LENGTH(Movie_Name) = 2;
SELECT Movie_Name, IMDB_Rating FROM Movie WHERE Movie_Name LIKE '__';
-- ❖ Query 1.10: Find the name and genre of all the movies whose name consists of at least 3 characters.
SELECT Movie_Name, Genre FROM Movie WHERE LENGTH(Movie_Name) >= 3;
SELECT Movie_Name, Genre FROM Movie WHERE Movie_Name LIKE '___%';
-- ❖ Query 1.Last: Find the name and IMDB rating of all the movies which contain at most 9 characters in their name.
SELECT Movie_Name, IMDB_Rating FROM Movie WHERE LENGTH(Movie_Name) <= 9;
SELECT Movie_Name, IMDB_Rating FROM Movie WHERE Movie_Name NOT LIKE '__________%';
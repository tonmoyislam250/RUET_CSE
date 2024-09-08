/* 1.1 Display the name, IMDb rating and genre of all the movies with an IMDB rating greater than or equal to 8.0.*/
SELECT Movie_Name,
    IMDB_Rating,
    Genre
FROM movie
WHERE IMDB_Rating >= 8.0;


/* Query 1.2: Find how many movies are there in each genre with an IMDB rating greater than or equal to 8.0.*/
SELECT Genre,
    COUNT(Genre) AS No_Of_Movies
FROM movie
WHERE IMDB_Rating >= 8.0
GROUP BY Genre;



/* 1.3 Find the name and the average IMDb rating of those genres whose average IMDb rating is greater than or equal to 8.0.*/
SELECT Genre, AVG(IMDB_Rating) AS Average_Rating
FROM movie
GROUP BY Genre
HAVING AVG(IMDB_Rating) >= 8.0;


/* 1.4 Find the name, number of films and number of awards of the director who directed the most number of movies.*/
SELECT Director_Name,
    No_Of_Films,
    No_Of_Awards
FROM director
WHERE No_Of_Films = (
        SELECT MAX(No_Of_Films)
        FROM director
);

/* 1.5 Find the name, current age, number of films and number of awards of the youngest actor. */

SELECT Actor_Name,
    (YEAR(CURRENT_DATE) - Birth_Year) AS Current_Age,
    No_Of_Films,
    No_Of_Awards
FROM actor
WHERE Birth_Year = (
        SELECT MAX(Birth_Year)
        FROM actor
);

/* 2.1 Find the name, number of films as a director, number of films as
an actor, number of awards as a director and number of awards as an actor of
all the directors. (If a director never acted in any film then number of films
and number of awards as an actor will be null) */

SELECT D.Director_Name,
    D.No_Of_Films AS No_Of_Films_Director,
    A.No_Of_Films AS No_Of_Films_Actor,
    D.No_Of_Awards AS No_Of_Awards_Director,
    A.No_Of_Awards AS No_Of_Awards_Actor
FROM director D
LEFT JOIN actor A ON D.Person_ID = A.Person_ID;

/* 2.2 Find the name, number of films as a director, number of films as
an actor, number of awards as a director and number of awards as an actor of
all the actors and directors. */

SELECT D.Director_Name,
    D.No_Of_Films AS No_Of_Films_Director,
    A.No_Of_Films AS No_Of_Films_Actor,
    D.No_Of_Awards AS No_Of_Awards_Director,
    A.No_Of_Awards AS No_Of_Awards_Actor
FROM director D
LEFT JOIN Actor A ON D.Person_ID = A.Person_ID
UNION
SELECT 
    A.Actor_Name AS Director_Name,
    NULL AS No_Of_Films_Director,
    A.No_Of_Films AS No_Of_Films_Actor,
    NULL AS No_Of_Awards_Director,
    A.No_Of_Awards AS No_Of_Awards_Actor
FROM Actor A
RIGHT JOIN Director D ON A.Person_ID = D.Person_ID;

/* 2.3 Find the name, number of films and number of awards of those
actors who never directed any film. */

SELECT 
    A.Actor_Name,
    A.No_Of_Films,
    A.No_Of_Awards
FROM Actor A
LEFT JOIN Director D ON A.Person_ID = D.Person_ID
WHERE D.Person_ID IS NULL;

/* 2.4 Find the name, IMDb rating and genre of those movies whose
IMDb Rating is above average */

SELECT 
    Movie_Name,
    IMDB_Rating,
    Genre
FROM Movie
WHERE IMDB_Rating > (SELECT AVG(IMDB_Rating) FROM Movie);

/* 2.5 Among the average IMDb ratings of all the movie genres, find
the highest average IMDb rating and display it */

SELECT 
    Genre,
    AVG(IMDB_Rating) AS Average_IMDB_Rating
FROM Movie
GROUP BY Genre
ORDER BY Average_IMDB_Rating DESC
LIMIT 1;

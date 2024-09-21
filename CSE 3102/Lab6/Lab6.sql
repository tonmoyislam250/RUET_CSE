-- Query 2.1: Find the name, year of release, IMDB rating of all the movies of
-- Byomkesh (N.B.: A movie of Byomkesh may not contain the term
-- ‘Byomkesh’ in its name)

SELECT Movie_Name, Year, IMDB_Rating
FROM movie
JOIN movie_Character_Relationship MCR ON MCR.movie_ID = movie.Movie_ID
WHERE Character_ID IN (
    SELECT Character_ID
    FROM movie_characters
    WHERE Character_Name LIKE '%Byomkesh%'
);

-- Query 2.2: Find the name of all the movies and, the name & the age of the
-- youngest movie-character in each movie

SELECT Movie_Name, Character_Name, Age
FROM movie
JOIN movie_Character_Relationship MCR ON MCR.movie_ID = movie.Movie_ID
JOIN movie_characters MC ON MC.Character_ID = MCR.Character_ID
WHERE Age = (
    SELECT MIN(Age)
    FROM movie_characters
    JOIN movie_Character_Relationship AS mcr ON mcr.Character_ID = movie_characters.Character_ID
    WHERE mcr.movie_ID = movie.Movie_ID
);


-- Query 2.3: Find the name and age of all the characters from the movies of
-- Feluda (N.B.: A movie of Feluda may not contain the term ‘Feluda’ in its
-- name).

SELECT 
    MC.Character_Name, 
    MC.Age
FROM 
    Movie_Characters MC
JOIN 
    Movie_Character_Relationship MCR ON MC.Character_ID = MCR.Character_ID
WHERE 
    MCR.Movie_ID IN (
        SELECT Movie_ID 
        FROM Movie_Character_Relationship
        WHERE Character_ID = (
            SELECT Character_ID 
            FROM Movie_Characters 
            WHERE Character_Name = 'Feluda'
        )
);


-- Query 2.4: Find the name and age of all the characters from the movies
-- directed by Satyajit Ray

-- 2.4.1: Without Join (using Subqueries)

SELECT 
    Character_Name, 
    Age
FROM 
    Movie_Characters
WHERE 
    Character_ID IN (
        SELECT Character_ID 
        FROM Movie_Character_Relationship
        WHERE Movie_ID IN (
            SELECT Movie_ID 
            FROM Movie
            WHERE Director_ID IN (
                SELECT Person_ID
                FROM Director
                WHERE Director_Name = 'Satyajit Ray'
            )
        )
    );


-- 2.4.2: With Join

SELECT 
    MC.Character_Name, 
    MC.Age
FROM 
    Movie_Characters MC
JOIN 
    Movie_Character_Relationship MCR ON MC.Character_ID = MCR.Character_ID
JOIN 
    Movie M ON MCR.Movie_ID = M.Movie_ID
JOIN 
    Director D ON M.Director_ID = D.Person_ID
WHERE 
    D.Director_Name = 'Satyajit Ray';


-- Query 2.5: Find the movie genre with highest average IMDb rating

SELECT 
    Genre, 
    AVG(IMDB_Rating) AS Avg_Rating
FROM 
    Movie
GROUP BY 
    Genre
HAVING 
    AVG(IMDB_Rating) = (
        SELECT 
            MAX(Avg_Rating)
        FROM 
            (SELECT 
                AVG(IMDB_Rating) AS Avg_Rating
             FROM 
                Movie
             GROUP BY 
                Genre) AS Genre_Avg
    );


-- INSERT INTO Movie (Movie_ID, Movie_Name, Genre, Release_Year, IMDB_Rating, Director_ID)
-- VALUES (12, 'Sonar Kella', 'Drama', 1874, 8.3, 3);
-- INSERT INTO movie_characters (Character_ID, Character_Name, Age)
-- VALUES (12, 'Feluda', 30);
-- INSERT INTO movie_character_relationship (Movie_ID, Character_ID)
-- VALUES (40, 12);

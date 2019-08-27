package by.itstep.demo.controller;

import by.itstep.demo.entity.Movie;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.ArrayList;
import java.util.List;


@Controller
public class MovieController {


    @RequestMapping("/")
    public String index(Model model) {

        List<Movie> movies = new ArrayList<>();
        movies.add(new Movie("Taxi", "1998", "Luc Besson", "comedy"));
        movies.add(new Movie("The Matrix", "1999", "The Wachowski Brothers", "science fiction"));
        movies.add(new Movie("Dumb and Dumber", "1994", "Peter Farrelly", "comedy"));
        model.addAttribute("movies", movies);

        return "index";
    }

    @GetMapping("/addMovie")
    public String addMovieForm(Model model) {
        model.addAttribute("movie", new Movie());
        return "movie";
    }


    @ResponseBody
    @PostMapping("/addMovie")
    public String addMovie(Movie movie) {
        return movie.toString();
    }


}

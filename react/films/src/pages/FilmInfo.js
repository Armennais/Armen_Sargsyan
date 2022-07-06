import React, { useState, useEffect, useContext } from "react";
import {useParams} from 'react-router-dom'
import '../styles/FilmInfo.css';
import { FilmContext } from "../Components/Context";

const FilmInfo = () =>{
    const {allFilms} = useContext(FilmContext)
    const [movie, setMovie] = useState({});
    const {id} = useParams();

    useEffect(() => {
        setMovie(allFilms.find((n) => n.id === Number(id)))
    }, []);
    return (
        <div className="descDiv">
            <h1 className="descTitle">
                {movie.title}
            </h1>
            <img className="descImg" src={movie.img}/>
            <p className="descParag">{movie.description}</p>
        </div>
        
    )
}
export default FilmInfo
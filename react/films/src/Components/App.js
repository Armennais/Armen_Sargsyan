import React, { useState } from "react";
import { BrowserRouter, Routes, Route, Outlet } from "react-router-dom";
import { FilmContext } from "./Context";
import list from "./ListMovies";
import Layout from "./Layout";
import Main from "../pages/Main";
import FilmInfo from "../pages/FilmInfo";
import Films from "../pages/FilmsPage";
import NotFoundPage from "../pages/NotFoundPage";

const AppFC = () => {
  const [allFilms, setAllFilms] = useState(list);
  return (
    <FilmContext.Provider
      value={{
        allFilms,
        setAllFilms,
      }}
    >
      <BrowserRouter>
        <Routes>
          <Route path="/" element={<Layout />}>
            <Route index element={<Main />} />
            <Route path="films/" element={<Outlet />}>
              <Route index element={<Films />} />
              <Route path=":id" element={<FilmInfo />} />
            </Route>
            <Route path="*" element={<NotFoundPage />} />
          </Route>
        </Routes>
      </BrowserRouter>
    </FilmContext.Provider>
  );
};
export default AppFC;

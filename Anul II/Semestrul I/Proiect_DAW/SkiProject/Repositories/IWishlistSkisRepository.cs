using SkiProject.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Repositories
{
    public interface IWishlistSkisRepository
    {
        IQueryable<WishlistSki> GetWishlistSkisIQueriable();
        void Create(WishlistSki wishlistSki);
        //void Update(WishlistSki wishlistSki);
        void Delete(WishlistSki wishlistSki);
    }
}

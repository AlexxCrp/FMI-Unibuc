using SkiProject.Entities;
using SkiProject.Models;
using SkiProject.Repositories;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Managers
{
    public class WishlistSkisManager : IWishlistSkisManager
    {
        private readonly IWishlistSkisRepository wishlistSkisRepository;

        public WishlistSkisManager(IWishlistSkisRepository wishlistSkisRepository)
        {
            this.wishlistSkisRepository = wishlistSkisRepository;
        }

        public void Create(WishlistSkiModel model)
        {
            var newWishlistSki = new WishlistSki
            {
                WishlistId = model.IdWishlist,
                SkiId = model.IdSki
            };

            wishlistSkisRepository.Create(newWishlistSki);
        }
/*
        public void Update(WishlistSkiModel model)
        {
            var wishlistSki = GetWishlistSkiById(model.IdWishlist, model.IdSki);

            wishlistSki.SkiId = model.IdSki;

            wishlistSkisRepository.Update(wishlistSki);
        }
*/
        public void Delete(string wishlistId, string skiId)
        {
            var wishlistSki = GetWishlistSkiById(wishlistId, skiId);

            wishlistSkisRepository.Delete(wishlistSki);
        }

        public List<WishlistSki> GetWishlistSkis()
        {
            return wishlistSkisRepository.GetWishlistSkisIQueriable().ToList();
        }

        public WishlistSki GetWishlistSkiById(string wishlistId, string skiId)
        {
            var wishlistSki = wishlistSkisRepository.GetWishlistSkisIQueriable()
                .FirstOrDefault(x => x.WishlistId == wishlistId && x.SkiId == skiId);

            return wishlistSki;
        }

        



     
    }
}

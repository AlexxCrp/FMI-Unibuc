using SkiProject.Entities;
using SkiProject.Models;
using SkiProject.Repositories;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Managers
{
    public class SkisManager : ISkisManager
    {
        private readonly ISkisRepository skisRepository;
        
        public SkisManager(ISkisRepository skisRepository)
        {
            this.skisRepository = skisRepository;
        }

        public void Create(SkiModel model)
        {
            var newSki = new Ski
            {
                Id = model.Id,
                Name = model.Name
            };

            skisRepository.Create(newSki);
        }

        public void Update(SkiModel model)
        {
            var ski = GetSkiById(model.Id);

            ski.Name = model.Name;
            skisRepository.Update(ski);
        }

        public void Delete(string id)
        {
            var ski = GetSkiById(id);

            skisRepository.Delete(ski);
        }

        public List<Ski> GetSkis()
        {
            return skisRepository.GetSkisIQueriable().ToList();
        }

        public Ski GetSkiById(string id)
        {
            var ski = skisRepository.GetSkisIQueriable()
                .FirstOrDefault(x => x.Id == id);

            return ski;
        }

        public List<Ski> GetSkisByBrand(string brandId)
        {
            var ski = skisRepository.GetSkisIQueriable()
                .Where(x => x.BrandId == brandId).ToList();

            return ski;
        }

        public List<MainSkiModel> GetSkisWithBrand()
        {
            var skisWithBrand = skisRepository.GetSkisWithBrandIQueryable()
                .Select(x => new MainSkiModel { Name = x.Name, Price = x.Price, Picture = x.PictureUrl, Brand = x.Brand.Name })
                .ToList();

            return skisWithBrand;
        }

        public List<MainSkiModel> GetSkisWithBrandOrdered()
        {
            var skisWithBrand = skisRepository.GetSkisWithBrandIQueryable()
                .Select(x => new MainSkiModel { Name = x.Name, Price = x.Price, Picture = x.PictureUrl, Brand = x.Brand.Name })
                .OrderBy(x => x.Price)
                .ToList();

            return skisWithBrand;
        }
    }
}

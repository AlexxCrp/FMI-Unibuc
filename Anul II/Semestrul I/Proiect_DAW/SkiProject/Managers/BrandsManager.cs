using SkiProject.Entities;
using SkiProject.Models;
using SkiProject.Repositories;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Managers
{
    public class BrandsManager : IBrandsManager
    {
        private readonly IBrandsRepository brandsRepository;

        public BrandsManager(IBrandsRepository brandsRepository)
        {
            this.brandsRepository = brandsRepository;
        }

        public void Create(BrandModel model)
        {
            var newBrand = new Brand
            {
                Id = model.Id,
                Name = model.Name
            };

            brandsRepository.Create(newBrand);
        }

        public void Update(BrandModel model)
        {
            var brand = GetBrandById(model.Id);

            brand.Name = model.Name;
            brandsRepository.Update(brand);
        }

        public void Delete(string id)
        {
            var brand = GetBrandById(id);

            brandsRepository.Delete(brand);
        }

        public List<Brand> GetBrands()
        {
            return brandsRepository.GetBrandsIQueryable().ToList();
        }

        public Brand GetBrandById(string id)
        {
            var brand = brandsRepository.GetBrandsIQueryable()
                .FirstOrDefault(x => x.Id == id);

            return brand;
        }

    }
}